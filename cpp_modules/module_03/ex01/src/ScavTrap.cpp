#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap()
    : ClapTrap("")
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap " << name_ << " has entered the battlefield!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap " << name_ << " has entered the battlefield!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap " << name_ << " has been copied!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name_ << " has left the battlefield!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << name_ << " has been assigned!" << std::endl;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name_ << " has entered in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints_ == 0 || hitPoints_ == 0)
    {
        std::cout << "ScavTrap " << name_ << " is out of energy or hit points!" << std::endl;
        return;
    }
    --energyPoints_;
    std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
}