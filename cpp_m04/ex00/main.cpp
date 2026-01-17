#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "                 SUBJECT TESTS (CORRECT)" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;
	std::cout << "J Type: " << j->getType() << " " << std::endl;
	std::cout << "I Type: " << i->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "--- Sounds ---" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "--- Destruction ---" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl
						<< std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "                 WRONG TESTS (NO VIRTUAL)" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "--- Sounds (Expect Wrong Output) ---" << std::endl;

	wrongCat->makeSound();

	wrongMeta->makeSound();

	std::cout << std::endl;
	std::cout << "--- Destruction ---" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}