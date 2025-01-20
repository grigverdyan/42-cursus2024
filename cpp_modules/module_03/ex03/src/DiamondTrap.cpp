#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap()
    : ClapTrap(""), ScavTrap(""), FragTrap("")
{
    std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name")
{
    this->name_ = name;
    hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;
    std::cout << "DiamondTrap " << this->name_ << " has entered the battlefield!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other.name_ + "_clap_name")
{
    *this = other;
    std::cout << "DiamondTrap " << this->name_ << " has been copied!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name_ << " has left the battlefield!" << std::endl;
}

