#include "ScavTrap.hpp"

int main() {
    std::cout << "--- CONSTRUCTING ---" << std::endl;
    ScavTrap gateKeeper("Serena");

    std::cout << "\n--- TESTING ATTACK (Should correspond to ScavTrap stats) ---" << std::endl;
    gateKeeper.attack("Intruder");

    std::cout << "\n--- TESTING GUARD GATE ---" << std::endl;
    gateKeeper.guardGate();

    std::cout << "\n--- DESTRUCTING (Check reverse order) ---" << std::endl;
    return 0;
}