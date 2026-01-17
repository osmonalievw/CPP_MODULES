#include "Zombie.hpp"

int main(void)
{
    std::cout << "--- HEAP ALLOCATION TEST ---" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");

    if (heapZombie)
        heapZombie->announce();

    delete heapZombie;

    std::cout << std::endl;

    std::cout << "--- STACK ALLOCATION TEST ---" << std::endl;
    randomChump("StackZombie");

    return (0);
}