/*
 * ======================================================================================
 * MAIN.CPP
 * ======================================================================================
 * * [EN] This file contains extensive stress tests for the Module 04 Exercise 03 project.
 * It verifies:
 * 1. Memory management and limit handling (MateriaSource & Character).
 * 2. Deep Copy logic (Copy Constructor & Assignment Operator).
 * 3. Interface implementation specifics.
 *
 * [JP] このファイルには、Module 04 Exercise 03 プロジェクトの広範なストレステストが含まれています。
 * 以下の点を確認します：
 * 1. メモリ管理と制限の処理（MateriaSource と Character）。
 * 2. ディープコピーのロジック（コピーコンストラクタと代入演算子）。
 * 3. インターフェース実装の詳細。
 * ======================================================================================
 */

#include <iostream>
#include "include/AMateria.hpp"
#include "include/Character.hpp"
#include "include/Cure.hpp"
#include "include/Ice.hpp"
#include "include/ICharacter.hpp"
#include "include/IMateriaSource.hpp"
#include "include/MateriaSource.hpp"

/*
 * [EN] Helper function to print visible headers for test sections.
 * [JP] テストセクションのヘッダーを表示するためのヘルパー関数です。
 */

void printHeader(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << " " << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int main()
{
	/* -------------------------------------------------------------------
	 * TEST 1: MateriaSource Limits & Unknown Types
	 * * [EN] We verify that MateriaSource can store up to 4 templates.
	 * We check if it handles the overflow (5th item) correctly without leaks.
	 * We also check if creating an unknown material returns NULL properly.
	 * * [JP] MateriaSourceが最大4つのテンプレートを保存できることを確認します。
	 * 5つ目のアイテム（オーバーフロー）をリークなしで適切に処理するか確認します。
	 * また、未知のマテリアを作成しようとした場合に正しくNULLが返されるか確認します。
	 * ------------------------------------------------------------------- */
	printHeader("TEST 1: MateriaSource Limits");

	IMateriaSource *src = new MateriaSource();

	// [EN] Learn 4 basic materias. The inventory should be full after this.
	// [JP] 基本的なマテリアを4つ学習させます。これでインベントリがいっぱいになるはずです。
	src->learnMateria(new Ice());	 // Slot 0
	src->learnMateria(new Cure()); // Slot 1
	src->learnMateria(new Ice());	 // Slot 2
	src->learnMateria(new Cure()); // Slot 3

	// [EN] Try to learn a 5th materia.
	//      Logic check: The source is full. Depending on implementation, it should likely delete
	//      the passed object to avoid a memory leak, because 'src' takes ownership of the pointer.
	// [JP] 5つ目のマテリアを学習させてみます。
	//      ロジック確認：ソースはいっぱいです。実装によりますが、'src' がポインタの所有権を持つため、
	//      メモリリークを防ぐために渡されたオブジェクトを削除する必要があります。
	std::cout << "-> Trying to learn 5th materia (should produce error/log):" << std::endl;
	src->learnMateria(new Ice());

	// [EN] Try to create a materia that has not been learned ("fire").
	//      Logic check: Should return NULL (0).
	// [JP] 学習していないマテリア（"fire"）を作成しようとします。
	//      ロジック確認：NULL（0）を返す必要があります。
	std::cout << "-> Trying to create unknown materia 'fire':" << std::endl;
	AMateria *tmp = src->createMateria("fire");
	if (tmp == NULL)
		std::cout << "OK: 'fire' not found, returned NULL." << std::endl;
	else
		std::cout << "FAIL: 'fire' created somehow!" << std::endl;

	/* -------------------------------------------------------------------
	 * TEST 2: Character Inventory & Equip/Unequip
	 * * [EN] We verify the Character's inventory limits (4 slots).
	 * We verify the 'unequip' behavior (should NOT delete memory).
	 * We check handling of invalid indices in 'use'.
	 * * [JP] Characterのインベントリ制限（4スロット）を確認します。
	 * 'unequip' の動作（メモリを削除してはいけない）を確認します。
	 * 'use' における無効なインデックスの処理を確認します。
	 * ------------------------------------------------------------------- */
	printHeader("TEST 2: Character Inventory Limits");
	ICharacter *bob = new Character("Bob");

	// [EN] Fill the inventory completely (4 items).
	// [JP] インベントリを完全に埋めます（4つのアイテム）。
	bob->equip(src->createMateria("ice"));	// Slot 0
	bob->equip(src->createMateria("cure")); // Slot 1
	bob->equip(src->createMateria("ice"));	// Slot 2
	bob->equip(src->createMateria("cure")); // Slot 3

	// [EN] Try to equip a 5th item.
	//      Logic check: Inventory is full. The Character should NOT equip it.
	// [JP] 5つ目のアイテムを装備しようとします。
	//      ロジック確認：インベントリはいっぱいです。Characterはこれを装備してはいけません。
	std::cout << "-> Trying to equip 5th item (should fail):" << std::endl;
	AMateria *extra = src->createMateria("ice");
	bob->equip(extra); // [EN] Nothing happens / [JP] 何も起こらないはずです

	// [EN] IMPORTANT: Since 'equip' did not take ownership of 'extra' (because inventory was full),
	//      WE must delete it here manually to prevent a memory leak in this test function.
	//      In a real game loop, the caller is responsible for unequipped items.
	// [JP] 重要：'equip' が 'extra' の所有権を持たなかったため（インベントリがいっぱいだったため）、
	//      このテスト関数内でのメモリリークを防ぐために、ここで手動で削除する必要があります。
	//      実際のゲームループでは、呼び出し元が装備されていないアイテムの責任を負います。
	delete extra;

	// [EN] Test 'unequip'.
	//      Rule: "The unequip() member function must NOT delete the Materia!"
	// [JP] 'unequip' のテスト。
	//      ルール："unequip() メンバ関数はマテリアを削除してはいけません！"
	std::cout << "-> Unequipping slot 0..." << std::endl;
	bob->unequip(0); // [EN] Slot 0 is now NULL / [JP] スロット0はNULLになります

	// [EN] NOTE: In a strictly correct program, we should have saved the pointer from slot 0
	//      before unequipping to delete it later. Since we didn't, this specific line technically leaks
	//      the item formerly in slot 0. This is expected behavior based on the Subject instructions
	//      ("Handle the Materias your character leaves on the floor as you like").
	// [JP] 注記：厳密に正しいプログラムでは、unequipする前にスロット0のポインタを保存し、後で削除する必要がありました。
	//      ここではそれを行っていないため、技術的には元々スロット0にあったアイテムがリークします。
	//      これは課題の指示に基づく想定された動作です（「床に置かれたマテリアの処理は自由」）。

	// [EN] Equip a new item into the now empty slot 0.
	// [JP] 空になったスロット0に新しいアイテムを装備します。
	std::cout << "-> Equipping into freed slot 0..." << std::endl;
	bob->equip(src->createMateria("ice"));

	// [EN] Test using invalid slots.
	//      Logic check: Should simply do nothing and NOT crash (Segfault).
	// [JP] 無効なスロットの使用をテストします。
	//      ロジック確認：単に何もせず、クラッシュ（セグメンテーション違反）してはいけません。
	std::cout << "-> Using invalid slots (should do nothing):" << std::endl;
	bob->use(-1, *bob); // [EN] Negative index / [JP] 負のインデックス
	bob->use(50, *bob); // [EN] Out of bounds / [JP] 範囲外
	bob->use(3, *bob);	// [EN] Valid index (should work) / [JP] 有効なインデックス（動作するはず）

	/* -------------------------------------------------------------------
	 * TEST 3: DEEP COPY (The most important test!)
	 * * [EN] We verify that the Copy Constructor creates a distinct copy.
	 * The copy must have its own Materias, not pointers to the original's Materias.
	 * * [JP] ディープコピー（最も重要なテスト！）
	 * コピーコンストラクタが別のコピーを作成することを確認します。
	 * コピーは、オリジナルのマテリアへのポインタではなく、独自のマテリアを持つ必要があります。
	 * ------------------------------------------------------------------- */
	printHeader("TEST 3: Deep Copy Check");

	Character *original = new Character("Original");
	original->equip(new Ice());

	// [EN] Create a copy using the Copy Constructor.
	// [JP] コピーコンストラクタを使用してコピーを作成します。
	Character *copy = new Character(*original);

	// [EN] Modify the Original (unequip slot 0).
	//      If it's a Shallow Copy, the Copy would also lose its item (since they share the pointer).
	//      If it's a Deep Copy, the Copy should keep its item.
	// [JP] オリジナルを変更します（スロット0をunequip）。
	//      もし浅いコピー（Shallow Copy）なら、コピーもアイテムを失います（ポインタを共有しているため）。
	//      もし深いコピー（Deep Copy）なら、コピーはアイテムを保持し続けるはずです。
	original->unequip(0);

	std::cout << "Original uses slot 0 (should do nothing): ";
	original->use(0, *copy); // [EN] Should be empty / [JP] 空のはずです

	std::cout << "Copy uses slot 0 (should shoot ice): ";
	copy->use(0, *original); // [EN] Should work! / [JP] 動作するはずです！

	// [EN] Delete the Original.
	//      If it's a Shallow Copy, deleting Original would destroy the Materia, leaving Copy with a dangling pointer.
	// [JP] オリジナルを削除します。
	//      もし浅いコピーなら、オリジナルを削除するとマテリアも破壊され、コピーはダングリングポインタ（無効なポインタ）を持つことになります。
	delete original;

	// [EN] Verify Copy still works.
	// [JP] コピーがまだ機能することを確認します。
	std::cout << "Copy uses slot 0 after Original death: ";
	copy->use(0, *copy);

	delete copy;

	/* -------------------------------------------------------------------
	 * TEST 4: Assignment Operator & Self-Assignment
	 * * [EN] We verify that the Assignment Operator (=) performs a deep copy.
	 * We also check that assigning an object to itself (a = a) doesn't break anything.
	 * * [JP] 代入演算子と自己代入のテスト
	 * 代入演算子（=）がディープコピーを行うことを確認します。
	 * また、オブジェクトを自分自身に代入（a = a）しても問題が起きないことを確認します。
	 * ------------------------------------------------------------------- */
	printHeader("TEST 4: Assignment & Self-Assignment");

	Character *c1 = new Character("C1");
	c1->equip(new Ice());

	Character *c2 = new Character("C2");
	c2->equip(new Cure());

	// [EN] Assignment: C1 = C2.
	//      Logic check:
	//      1. C1's old "Ice" must be deleted (no memory leak).
	//      2. C1 must create a NEW copy of C2's "Cure".
	// [JP] 代入：C1 = C2。
	//      ロジック確認：
	//      1. C1の古い「Ice」は削除されなければなりません（メモリリークなし）。
	//      2. C1はC2の「Cure」の新しいコピーを作成しなければなりません。
	std::cout << "-> Assigning C1 = C2..." << std::endl;
	*c1 = *c2;

	c1->use(0, *c2); // [EN] Should use Cure now / [JP] Cureを使用するはずです

	// [EN] Self-Assignment: C2 = C2.
	//      Logic check: The code must handle 'this == &other' and do nothing.
	//      If not handled, it might delete its own inventory before copying, causing a crash.
	// [JP] 自己代入：C2 = C2。
	//      ロジック確認：コードは 'this == &other' を処理し、何もしてはいけません。
	//      処理されていない場合、コピーする前に自分のインベントリを削除してしまい、クラッシュする可能性があります。
	std::cout << "-> Self-assignment C2 = C2..." << std::endl;
	*c2 = *c2;
	c2->use(0, *c1); // [EN] Should still work / [JP] まだ動作するはずです

	// [EN] Cleanup
	// [JP] 後処理
	delete c1;
	delete c2;
	delete bob;
	delete src;

	printHeader("ALL TESTS FINISHED");
	return 0;
}
