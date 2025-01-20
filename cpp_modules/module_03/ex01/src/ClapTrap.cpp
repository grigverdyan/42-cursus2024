#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    : name_(name)
    , hitPoints_(10)
    , energyPoints_(10)
    , attackDamage_(0)
{
    std::cout << "ClapTrap " << name_ << " has entered the battlefiled!" << std::endl;
}

ClapTrap::ClapTrap()
    : name_("")
    , hitPoints_(10)
    , energyPoints_(10)
    , attackDamage_(0)
{
    std::cout << "ClapTrap " << name_ << " has entered the battlefiled!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name_ << " has left the battlefield!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_)
    , hitPoints_(other.hitPoints_)
    , energyPoints_(other.energyPoints_)
    , attackDamage_(other.attackDamage_)
{
    std::cout << "ClapTrap " << name_ << " has been copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name_ = other.name_;
        hitPoints_ = other.hitPoints_;
        energyPoints_ = other.energyPoints_;
        attackDamage_ = other.attackDamage_;
        std::cout << "ClapTrap " << name_ << " has been assigned!" << std::endl;
    }
    return *this;
}

const std::string& ClapTrap::getName() const
{
    return name_;
}

unsigned int ClapTrap::getHitPoints() const
{
    return hitPoints_;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return energyPoints_;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return attackDamage_;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints_ == 0 || hitPoints_ == 0)
    {
        std::cout << "ClapTrap " << name_ << " has no energy or points left to attack!" << std::endl;
        return;
    }
    --energyPoints_;
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints_ == 0)
    {
        std::cout << "ClapTrap " << name_ << " is already dead!" << std::endl;
        return;
    }
    if (amount >= hitPoints_)
    {
        hitPoints_ = 0;
        std::cout << "ClapTrap " << name_ << " has been killed!" << std::endl;
    }
    else
    {
        hitPoints_ -= amount;
        std::cout << "ClapTrap " << name_ << " has taken " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints_ == 0 || energyPoints_ == 0)
    {
        std::cout << "ClapTrap " << name_ << " has no energy or hit points left to repair itself!" << std::endl;
        return;
    }
    ++energyPoints_;
    hitPoints_ += amount;
    std::cout << "ClapTrap " << name_ << " has been repaired for " << amount << " hit points!" << std::endl 
              << "New HP: " << hitPoints_ << std::endl;
}