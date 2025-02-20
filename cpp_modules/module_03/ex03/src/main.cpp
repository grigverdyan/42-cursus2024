#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    DiamondTrap DiamondA("DiamondOne");
    std::cout << "DiamondTrap's attackDamage: " << DiamondA.getAttackDamage() << std::endl;
    std::cout << "DiamondTrap's energy Points: " << DiamondA.getEnergyPoints() << std::endl;
    std::cout << "DiamondTrap's hit Points: " << DiamondA.getHitPoints() << std::endl;
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