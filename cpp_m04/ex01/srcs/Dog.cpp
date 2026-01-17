#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "[" << this->type << "]    Default constructor called: A loyal dog appears!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "[" << this->type << "] Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
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

Dog::~Dog()
{
	delete this->brain;
	std::cout << "[" << this->type << "]    Destructor called: The dog runs to a farm upstate." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}