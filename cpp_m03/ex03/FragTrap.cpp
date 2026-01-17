#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << this->name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    *this = other;
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) ClapTrap::operator=(other);
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}
FragTrap::~FragTrap(void) { std::cout << "FragTrap " << this->name << " destroyed" << std::endl; }

void FragTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "FragTrap " << name << " can't attack!" << std::endl;
        return;
    }

    _energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"
              << std::endl;
}

void FragTrap::highFivesGuys(void) { std::cout << "FragTrap " << this->name << " high five request" << std::endl; }