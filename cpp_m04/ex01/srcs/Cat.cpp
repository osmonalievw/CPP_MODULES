#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "[" << this->type << "]    Default constructor called: A mysterious cat appears!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "[" << this->type << "] Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		delete brain;
		this->brain = new Brain(*other.brain);
		Animal::operator=(other);
	}
	std::cout << "[" << this->type << "]    Copy assignment operator called." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "[" << this->type << "]    Destructor called: The cat is gone." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
