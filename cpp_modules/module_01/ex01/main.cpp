#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(8, "Asterin");

    zombies[0].announce();
    zombies[1].announce();
    zombies[2].announce();
    zombies[3].announce();
    zombies[4].announce();
    zombies[5].announce();
    zombies[6].announce();
    zombies[7].announce();
    
    delete[] zombies;

    return 0;
}