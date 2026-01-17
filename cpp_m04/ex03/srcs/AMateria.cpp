#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

AMateria::AMateria() : type("Default_abstract")
{
	// std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	// std::cout << "[AMateria] Param constructor called with type: " << this->type << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	this->type = other.type;
	// std::cout << "[AMateria] Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->type = other.type;
	// std::cout << "[AMateria] Copy assignment operator called" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	// std::cout << "[AMateria] Destructor called for " << this->type << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}
void AMateria::use(ICharacter &target)
{
	std::cout << "* generic materia use on " << target.getName() << " *" << std::endl;
}
