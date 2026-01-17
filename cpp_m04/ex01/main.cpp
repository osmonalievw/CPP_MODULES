#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

#define N 4

int main()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "              TEST 1: ARRAY OF ANIMALS" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	const Animal *animals[N];

	std::cout << "--- [1] Creating Animals ---" << std::endl;
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl
						<< "--- [2] Testing Sounds ---" << std::endl;
	for (int i = 0; i < N; i++)
	{
		animals[i]->makeSound();
	}

	std::cout << std::endl
						<< "--- [3] Deleting Animals ---" << std::endl;

	for (int i = 0; i < N; i++)
	{
		delete animals[i];
	}

	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "              TEST 2: DEEP COPY PROOF" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "--- [1] Creating Original Dog ---" << std::endl;
	Dog *dog1 = new Dog();

	std::cout << std::endl
						<< "--- [2] Creating Copy (Deep Copy) ---" << std::endl;
	Dog *dog2 = new Dog(*dog1);

	std::cout << std::endl
						<< "--- [3] Deleting Original Dog ---" << std::endl;
	delete dog1;

	std::cout << std::endl
						<< "--- [4] Testing Copy ---" << std::endl;

	dog2->makeSound();

	std::cout << std::endl
						<< "--- [5] Deleting Copy ---" << std::endl;
	delete dog2;

	std::cout << std::endl
						<< "-------------------------------------------------------" << std::endl;
	std::cout << "              TEST FINISHED" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	return 0;
}