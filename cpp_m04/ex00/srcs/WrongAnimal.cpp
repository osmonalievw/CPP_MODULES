#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("DefaultWrongAnimal")
{
	std::cout << "[" << this->type << "] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
	std::cout << "[" << this->type << "] Param constructor called: Created a " << type << "." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{

	this->type = other.type;
	std::cout << "[" << this->type << "] Copy constructor called: Cloning an WrongAnimal." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[" << this->type << "] Copy assignment operator called." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() { std::cout << "[" << this->type << "] Destructor called" << std::endl; }

void WrongAnimal::makeSound() const
{
	std::cout << "* Generic WrongAnimal noises *" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "[" << this->type << "]    Default constructor called: A mysterious WrongCat appears!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "[" << this->type << "] Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "[" << this->type << "]    Copy assignment operator called." << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[" << this->type << "]    Destructor called: The WrongCat is gone." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
