#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap()
    : ClapTrap(""), ScavTrap(""), FragTrap("")
{
    std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name")
    , ScavTrap(name)
    , FragTrap(name)
    , name_(name)
{
    hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::initialEnergyPoints;
    attackDamage_ = FragTrap::attackDamage_;
    std::cout << "DiamondTrap " << this->name_ << " has entered the battlefield!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other.ClapTrap::name_), ScavTrap(other), FragTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap " << this->name_ << " has been copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        
        this->name_ = other.name_;
        this->hitPoints_ = other.hitPoints_;
        this->energyPoints_ = other.energyPoints_;
        this->attackDamage_ = other.attackDamage_;
    }
    std::cout << "DiamondTrap " << name_ << " has been assigned!" << std::endl;
    return *this;
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name_ << " has left the battlefield!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Hi, my name is " << this->name_ << ".\nClapTrap's name is " << ClapTrap::name_ << ".\n";
}
