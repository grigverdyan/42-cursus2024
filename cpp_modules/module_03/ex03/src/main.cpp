#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    DiamondTrap DiamondA("DiamondOne");
    DiamondA.takeDamage(3);
    DiamondA.attack("Trap");
    DiamondA.whoAmI();
    
    DiamondTrap DiamondB(DiamondA);
    DiamondB.whoAmI();
    DiamondB.attack("Shadow");
    DiamondB.takeDamage(20);
    
    DiamondTrap DiamondC;
    DiamondC = DiamondA;
    DiamondC.whoAmI();
    DiamondC.beRepaired(10);

    DiamondA.takeDamage(1000);
    DiamondA.attack("Ghost");
    DiamondA.beRepaired(50);

    return 0;
}