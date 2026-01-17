#include "Animal.hpp"

Animal::Animal() : type("DefaultAnimal")
{
    std::cout << "[" << this->type << "] Default constructor called" << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
    std::cout << "[" << this->type << "] Param constructor called: Created a " << type << "." << std::endl;
}

Animal::Animal(const Animal &other)
{

    this->type = other.type;
    std::cout << "[" << this->type << "] Copy constructor called: Cloning an animal." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "[" << this->type << "] Copy assignment operator called." << std::endl;
    return (*this);
}

Animal::~Animal() { std::cout << "[" << this->type << "] Destructor called" << std::endl; }

void Animal::makeSound() const
{
    std::cout << "* Generic animal noises *" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
