#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    *this = other;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) ClapTrap::operator=(other);
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}
ScavTrap::~ScavTrap(void) { std::cout << "ScavTrap " << this->name << " destroyed" << std::endl; }

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ScavTrap " << name << " can't attack!" << std::endl;
        return;
    }

    _energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}