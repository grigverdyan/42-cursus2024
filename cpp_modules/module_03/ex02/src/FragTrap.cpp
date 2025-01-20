#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(const std::string& name) 
    : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " has entered the battlefield!" << std::endl;
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
}

FragTrap::FragTrap() 
    : ClapTrap("")
{
    std::cout << "FragTrap " << name_ << " has entered the battlefield!" << std::endl;
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name_ << " has left the battlefield!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap " << name_ << " has been copied!" << std::endl;
    hitPoints_ = other.hitPoints_;
    energyPoints_ = other.energyPoints_;
    attackDamage_ = other.attackDamage_;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    { 
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << name_ << " has been assigned!" << std::endl;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name_ << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints_ == 0 || hitPoints_ == 0)
    {
        std::cout << "FragTrap " << name_ << " is out of energy or hit points!" << std::endl;
        return;
    }
    --energyPoints_;
    std::cout << "FragTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
}