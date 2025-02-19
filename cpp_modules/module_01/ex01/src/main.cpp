#include "Zombie.hpp"
#include <iostream>

int main()
{
    const size_t zombieCount = 8;
    Zombie *zombies = zombieHorde(zombieCount, "Asterin");

    for (size_t i = 0; i < zombieCount; ++i)
    {
        zombies[i].announce();
    }
    
    delete[] zombies;

    return 0;
}