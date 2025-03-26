
#include "Zombie.hpp"

int main()
{
    int N = 10;
    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;

    Zombie* zombies = zombieHorde(N, "Horde Zombie");

    for(int i = 0; i < N; i++)
    {
        zombies[i].announce();
    }

    delete[] zombies;

    std::cout << "All zombies have been destroyed." << std::endl;

    return (0);
}
