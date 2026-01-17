#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "[" << this->type << "]    Default constructor called: A loyal dog appears!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "[" << this->type << "] Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "[" << this->type << "]    Copy assignment operator called." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[" << this->type << "]    Destructor called: The dog runs to a farm upstate." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}