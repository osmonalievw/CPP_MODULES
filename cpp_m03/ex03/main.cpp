#include <iostream>

#include "DiamondTrap.hpp"

int main() {
    std::cout << "\033[1;32m--- TEST 1: NAMED CONSTRUCTOR & METHODS ---\033[0m" << std::endl;
    {
        DiamondTrap d1("DIAMOND_01");

        d1.whoAmI();
        d1.attack("Target_A");
        d1.guardGate();
        d1.highFivesGuys();
    }

    std::cout << "\n\033[1;32m--- TEST 2: COPY CONSTRUCTOR ---\033[0m" << std::endl;
    {
        DiamondTrap original("ORIGINAL");
        DiamondTrap copy(original);
        copy.whoAmI();
    }

    std::cout << "\n\033[1;32m--- TEST 3: ASSIGNMENT OPERATOR ---\033[0m" << std::endl;
    {
        DiamondTrap worker("WORKER");
        DiamondTrap boss("BOSS");

        boss = worker;
        boss.whoAmI();
    }

    std::cout << "\n\033[1;32m--- TEST 4: DEFAULT CONSTRUCTOR ---\033[0m" << std::endl;
    {
        DiamondTrap def;
        def.whoAmI();
    }

    std::cout << "\n\033[1;32m--- LEAKS CHECK ---\033[0m" << std::endl;
    system("leaks -q diamondtrap");

    return 0;
}