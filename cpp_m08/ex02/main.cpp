#include <iostream>
#include <string>
#include <list>
#include "MutantStack.hpp"

// A helper template function to print the stack forward
template <typename T>
void printStack(MutantStack<T> &mstack, const std::string &name)
{
	std::cout << "--- " << name << " (Base Iterator) ---" << std::endl;
	std::cout << " { ";
	for (typename MutantStack<T>::iter it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << "[" << *it << "] ";
	}
	std::cout << "}" << std::endl;
}

// A helper template function to print the stack in reverse
template <typename T>
void printStackReverse(MutantStack<T> &mstack, const std::string &name)
{
	std::cout << "--- " << name << " (Reverse Iterator) ---" << std::endl;
	std::cout << "{ ";
	for (typename MutantStack<T>::riter it = mstack.rbegin(); it != mstack.rend(); ++it)
	{
		std::cout << "[" << *it << "] ";
	}
	std::cout << "}" << std::endl;
}

int main()
{
	std::cout << "========== 1. SUBJECT PDF TEST (INT) ==========" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iter it = mstack.begin();
	MutantStack<int>::iter ite = mstack.end();
	++it;
	--it;
	std::cout << "[ ";
	while (it != ite)
	{
		std::cout << "[" << *it << "] ";
		++it;
	}
	std::cout << "]" << std::endl;

	// Testing implicit copy from MutantStack to std::stack
	std::stack<int> s(mstack);

	std::cout << "\n========== 2. STRING TYPE & REVERSE ITERATOR TEST ==========" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("from");
	strStack.push("MutantStack!");

	printStack(strStack, "strStack");
	printStackReverse(strStack, "strStack");

	std::cout << "\n========== 3. OCF (COPY & ASSIGNMENT) TEST ==========" << std::endl;
	// Copy Constructor Test
	MutantStack<std::string> copiedStack(strStack);
	std::cout << "Popping top of copiedStack (" << copiedStack.top() << ")...\n";
	copiedStack.pop();

	printStack(strStack, "Original strStack");
	printStack(copiedStack, "Copied strStack (should be missing last element)");

	// Assignment Operator Test
	MutantStack<std::string> assignedStack;
	assignedStack = copiedStack;
	printStack(assignedStack, "Assigned Stack (should match Copied Stack)");

	std::cout << "\n========== 4. WEAK PLACES & EDGE CASES ==========" << std::endl;

	std::cout << "Edge Case A: Iterating an completely empty stack (Char Type)" << std::endl;
	MutantStack<char> emptyStack;
	std::cout << "Is emptyStack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
	for (MutantStack<char>::iter e_it = emptyStack.begin(); e_it != emptyStack.end(); ++e_it)
	{
		std::cout << "ERROR: This should not print!" << std::endl;
	}
	std::cout << "Empty iteration passed safely without crashing." << std::endl;

	std::cout << "\nEdge Case B: Modifying elements through iterators" << std::endl;
	// Iterators should allow us to edit the elements directly in memory, bypassing standard stack rules!
	MutantStack<int> modStack;
	modStack.push(10);
	modStack.push(20);

	MutantStack<int>::iter mod_it = modStack.begin(); // Points to 10 (bottom of stack)
	*mod_it = 999;																		// Change the bottom element!

	printStack(modStack, "Modified Stack (Bottom element '10' should now be '999')");

	return 0;
}