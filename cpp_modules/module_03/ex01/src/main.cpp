#include "ScavTrap.hpp"

#include <iostream>

int main()
{
	ScavTrap ScavA("Liliane");
	ScavA.guardGate();
	ScavA.attack("Manon");
	ScavA.takeDamage(20);

	ScavTrap ScavB(ScavA);
	ScavB.beRepaired(5);
	ScavB.beRepaired(1);

	ScavTrap ScavC = ScavA;
	ScavC.takeDamage(20);
	ScavC.attack("Zolanda");

	return 0;
}