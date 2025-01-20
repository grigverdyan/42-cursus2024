#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap1("ClapTrap1");
	ClapTrap claptrap2("ClapTrap2");

	claptrap1.attack(claptrap2.getName());
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);

	return 0;
}