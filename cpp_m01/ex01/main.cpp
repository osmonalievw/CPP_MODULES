#include "Zombie.hpp"

#define N_ZOMBIES 5

int main(void)
{
    std::cout << "--- CREATING HORDE ---" << std::endl;

    Zombie* horde = zombieHorde(N_ZOMBIES, "CloneTrooper");

    if (horde == NULL)
    {
        std::cout << "Error: Allocation failed." << std::endl;
        return (1);
    }

    std::cout << "--- ANNOUNCING HORDE ---" << std::endl;

    for (int i = 0; i < N_ZOMBIES; i++)
    {
        horde[i].announce();
    }

    std::cout << "--- DESTROYING HORDE ---" << std::endl;

    delete [] horde;

    return (0);
}