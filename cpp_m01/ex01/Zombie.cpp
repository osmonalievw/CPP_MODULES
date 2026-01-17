#include "Zombie.hpp"

Zombie::Zombie() {};
// Zombie::Zombie(std::string name_in) : name(name_in)
// {
// 	std::cout << this->name << ":  Here is" << std::endl;
// };

Zombie::~Zombie(void)
{
	std::cout << name << ": has been destroyed" << std::endl;
};

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

void Zombie::setName(std::string name)
{
	this->name = name;
}