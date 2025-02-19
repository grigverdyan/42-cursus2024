#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("Abrokhas");
    zombie->announce();

    randomChump("Kalimba");
    
    delete zombie;

    return 0;
}