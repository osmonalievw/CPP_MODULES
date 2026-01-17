#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string Name) : name(Name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructed" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap " << name << " destroyed" << std::endl; }

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack!" << std::endl;
        return;
    }

    _energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }
    if (_hitPoints <= amount) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes massive damage and dies!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage! HP: " << _hitPoints << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't repaire!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
}