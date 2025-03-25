
#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("Heap Walker");
    heapZombie->announce();

    randomChump("Stack Crawler");

    heapZombie->announce();

    delete heapZombie;

    return (0);
}
