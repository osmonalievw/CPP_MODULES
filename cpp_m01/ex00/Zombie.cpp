#include "Zombie.hpp"

Zombie::Zombie(std::string name_in) : name(name_in) {};

Zombie::~Zombie(void) { std::cout << name << ": has been destroyed" << std::endl; };

void Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; };