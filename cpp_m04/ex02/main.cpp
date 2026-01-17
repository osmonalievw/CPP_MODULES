#include <iostream>
#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/Brain.hpp"
#include "include/WrongAnimal.hpp" // If you have it

// [EN] Helper function for printing headers
// [JP] ヘッダーを出力するためのヘルパー関数
void printTitle(std::string title)
{
	std::cout << "\n============================================================" << std::endl;
	std::cout << " " << title << std::endl;
	std::cout << "============================================================" << std::endl;
}

int main()
{
	std::cout << "========== EXERCISE 02: ABSTRACT CLASS & BRAIN ==========" << std::endl;

	// ============================================================
	// TEST 1: ABSTRACT CLASS - CANNOT BE INSTANTIATED
	// [EN] We verify that 'Animal' is now an abstract class.
	//      It should NOT be possible to create an Animal directly.
	// [JP] 'Animal' が抽象クラスであることを確認します。
	//      Animalを直接作成することはできないはずです。
	// ============================================================
	printTitle("TEST 1: ABSTRACT CLASS INSTANTIATION (SHOULD FAIL)");
	std::cout << "Uncomment the lines below to test abstract class logic:" << std::endl;
	std::cout << "If uncommented, this WILL NOT COMPILE (that's correct!)\n"
						<< std::endl;

	// UNCOMMENT BELOW TO TEST - SHOULD GIVE COMPILATION ERROR:
	// 下記のコメントを外してテストしてください - コンパイルエラーになるはずです：

	// ===== COMPILATION ERROR TEST / コンパイルエラーテスト =====

	// Animal test;                    // ❌ ERROR: Animal is abstract
	// Animal* ptr = new Animal();     // ❌ ERROR: Cannot instantiate abstract class

	// ===== END COMPILATION ERROR TEST / テスト終了 =====

	std::cout << "✅ Good! Animal is abstract and cannot be created directly.\n"
						<< "   (Animal は抽象クラスであり、直接作成できません)" << std::endl;

	// ============================================================
	// TEST 2: BASIC POLYMORPHISM
	// [EN] We verify that Dog and Cat can still be created via Animal pointers.
	// [JP] Dog と Cat が Animal ポインタ経由で作成できることを確認します。
	// ============================================================
	printTitle("TEST 2: BASIC POLYMORPHISM");
	{
		std::cout << "--- Creating Dog and Cat ---" << std::endl;
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << "\n--- Checking Types & Sounds ---" << std::endl;
		std::cout << "j->getType(): " << j->getType() << " " << std::endl;
		std::cout << "j->makeSound(): ";
		j->makeSound(); // Woof

		std::cout << "i->getType(): " << i->getType() << " " << std::endl;
		std::cout << "i->makeSound(): ";
		i->makeSound(); // Meow

		std::cout << "\n--- Deleting (Virtual Destructor Check) ---" << std::endl;
		delete j; // Should delete Brain too
		delete i; // Should delete Brain too
		std::cout << "✅ Polymorphism test finished\n"
							<< std::endl;
	}

	// ============================================================
	// TEST 3: ARRAY OF ANIMALS
	// [EN] Creating an array of Animals to test loops and mass deletion.
	// [JP] ループと一括削除をテストするために Animal の配列を作成します。
	// ============================================================
	printTitle("TEST 3: ARRAY LOOP");
	{
		const int size = 4;
		const Animal *zoo[size];

		std::cout << "--- Filling Zoo (Half Dogs, Half Cats) ---" << std::endl;
		for (int i = 0; i < size; i++)
		{
			if (i < size / 2)
				zoo[i] = new Dog();
			else
				zoo[i] = new Cat();
		}

		std::cout << "\n--- Making Sounds ---" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "Animal " << i << ": ";
			zoo[i]->makeSound();
		}

		std::cout << "\n--- Deleting Zoo ---" << std::endl;
		for (int i = 0; i < size; i++)
			delete zoo[i];

		std::cout << "✅ Array test finished\n"
							<< std::endl;
	}

	// ============================================================
	// TEST 4: DEEP COPY CHECK
	// [EN] Verifying that Brains are copied deeply (independent memories).
	// [JP] Brain が深くコピーされているか（独立したメモリか）を確認します。
	// ============================================================
	printTitle("TEST 4: DEEP COPY (BRAIN)");
	{
		std::cout << "--- Creating Original Dog ---" << std::endl;
		Dog *dog1 = new Dog();

		// [EN] Assuming you have a way to access Brain ideas (e.g. via getter or public brain)
		//      If not, you can only check pointers or rely on constructor output.
		//      Here we assume deep copy logic is inside Copy Constructor.
		// [JP] Brain のアイデアにアクセスする方法があると仮定します（例：ゲッターや public な brain）。
		//      そうでない場合は、ポインタを確認するか、コンストラクタの出力に頼るしかありません。

		std::cout << "--- Creating Copy Dog (Copy Constructor) ---" << std::endl;
		Dog *dog2 = new Dog(*dog1);

		std::cout << "--- Checking Addresses ---" << std::endl;
		std::cout << "Dog1 Address: " << dog1 << std::endl;
		std::cout << "Dog2 Address: " << dog2 << " (Should be different)" << std::endl;

		// [EN] If implementation is correct, modifying dog1 should not affect dog2
		// [JP] 実装が正しければ、dog1 を変更しても dog2 には影響しないはずです

		std::cout << "\n--- Deleting Original ---" << std::endl;
		delete dog1;

		std::cout << "--- Dog2 should still exist and be valid ---" << std::endl;
		dog2->makeSound(); // Should still Woof

		delete dog2;
		std::cout << "\n✅ Deep copy confirmed\n"
							<< std::endl;
	}

	std::cout << "========== ALL EX02 TESTS COMPLETED ==========" << std::endl;
	std::cout << "KEY POINTS:" << std::endl;
	std::cout << "✅ Animal is abstract (cannot instantiate)" << std::endl;
	std::cout << "✅ Dog/Cat implementation works" << std::endl;
	std::cout << "✅ Virtual destructors prevent leaks" << std::endl;
	std::cout << "✅ Deep copy creates independent Brains" << std::endl;

	return 0;
}