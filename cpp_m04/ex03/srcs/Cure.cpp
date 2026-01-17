#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "[Cure] Default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	// std::cout << "[Cure] Copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	// std::cout << "[Cure] Copy assignment operator called" << std::endl;
	return *this;
}

Cure::~Cure()
{
	// std::cout << "[Cure] Destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}