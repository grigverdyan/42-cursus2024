#include "FragTrap.hpp"

#include <iostream>

int main()
{
	FragTrap FragA("Mister");
	FragA.highFivesGuys();
	FragA.attack("Clown");
	FragA.takeDamage(30);

	FragTrap FragB(FragA);
	FragB.beRepaired(13);
	FragB.beRepaired(12);

	FragTrap FragC = FragA;
	FragC.takeDamage(2);
	FragC.takeDamage(310);
	FragC.attack("Blackbeak");
	FragC.highFivesGuys();

	return 0;
}