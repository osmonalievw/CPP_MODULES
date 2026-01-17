#include "../include/Character.hpp"
#include "../include/AMateria.hpp"

Character::Character() : name("Default")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// std::cout << "[Character] Default constructor called (Unnamed)" << std::endl;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// std::cout << "[Character] Param constructor called for " << this->name << std::endl;
}

Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	// std::cout << "[Character] Copy constructor called for " << this->name << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	// std::cout << "[Character] Copy assignment operator called" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	//	std::cout << "[Character] Destructor called for " << this->name << std::endl;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			// std::cout << "[Character] " << this->name << " equipped " << m->getType() << std::endl;
			return;
		}
	}
	// std::cout << "[Character] Inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		this->inventory[idx] = NULL;
		// std::cout << "[Character] " << this->name << " unequipped slot " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter &target)
{

	if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}