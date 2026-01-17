#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    std::cout << "\n\033[1;33m--- TEST 1: CLAPTRAP (The Original) ---\033[0m" << std::endl;
    {
        ClapTrap clap("CLAPPY");
        clap.attack("Target A");
        clap.takeDamage(5);
        clap.beRepaired(3);
    }
    std::cout << "\n\033[1;33m--- TEST 2: SCAVTRAP (The Gate Keeper) ---\033[0m" << std::endl;
    {
        ScavTrap scav("SCAVVY");
        scav.attack("Target B");
        scav.guardGate();
        scav.takeDamage(50);
        scav.beRepaired(20);
    }
    std::cout << "\n\033[1;33m--- TEST 3: FRAGTRAP (The High Fiver) ---\033[0m" << std::endl;
    {
        FragTrap frag("FRAGGY");
        frag.attack("Target C");
        frag.highFivesGuys();
        frag.takeDamage(20);
        frag.beRepaired(20);
    }
    std::cout << "\n\033[1;33m--- TEST 4: default CLAPTRAP (The Original) ---\033[0m" << std::endl;
    {
        ClapTrap clap2;
        clap2.attack("Target A");
        clap2.takeDamage(5);
        clap2.beRepaired(3);
    }
    std::cout << "\n\033[1;33m--- TEST 5: default SCAVTRAP (The Gate Keeper) ---\033[0m" << std::endl;
    {
        ScavTrap scav2;
        scav2.attack("Target B");
        scav2.guardGate();
        scav2.takeDamage(50);
        scav2.beRepaired(20);
    }
    std::cout << "\n\033[1;33m--- TEST 6: defaultFRAGTRAP (The High Fiver) ---\033[0m" << std::endl;
    {
        FragTrap frag2;
        frag2.attack("Target C");
        frag2.highFivesGuys();
        frag2.takeDamage(20);
        frag2.beRepaired(20);
    }
    std::cout << "\n\033[1;31m--- TEST 7: POLYMORPHISM (ClapTrap* -> ScavTrap) ---\033[0m" << std::endl;
    {
        ClapTrap* ptr = new ScavTrap("PtrScav");

        // ptr->guardGate(); COMPILE FAIL

        ptr->attack("Enemy");

        std::cout << "Deleting ptr..." << std::endl;
        delete ptr;
    }

    std::cout << "\n\033[1;31m--- TEST 8: POLYMORPHISM (ClapTrap* -> FragTrap) ---\033[0m" << std::endl;
    {
        ClapTrap* ptr = new FragTrap("PtrFrag");

        // ptr->highFivesGuys(); COMPILE FAIL

        ptr->takeDamage(10);

        std::cout << "Deleting ptr..." << std::endl;
        delete ptr;
    }
    std::cout << "\n\033[1;32m--- LEAKS CHECK ---\033[0m" << std::endl;
    system("leaks -q fragtrap");

    return 0;
}