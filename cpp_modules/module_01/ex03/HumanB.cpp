#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string& name)
    : name_(name)
    , weapon_(NULL)
{}

void HumanB::setWeapon(Weapon& weapon)
{
    weapon_ = &weapon;
}

void HumanB::attack()
{
    std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}