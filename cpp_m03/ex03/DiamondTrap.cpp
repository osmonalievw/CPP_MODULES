#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default") {
    this->FragTrap::_hitPoints = 100;
    this->ScavTrap::_energyPoints = 50;
    this->FragTrap::_attackDamage = 30;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
    this->FragTrap::_hitPoints = 100;
    this->ScavTrap::_energyPoints = 50;
    this->FragTrap::_attackDamage = 30;
    std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    *this = other;
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap(void) { std::cout << "DiamondTrap " << this->_name << " destroyed" << std::endl; }

void DiamondTrap::whoAmI() {
    std::cout << "My name is: " << this->_name << std::endl;
    std::cout << "My ClapTrap name is: " << this->ClapTrap::name << std::endl;
}
