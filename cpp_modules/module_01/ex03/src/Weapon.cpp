#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) 
    : type_(type)
{}

const std::string& Weapon::getType()
{
    return type_;
}

void Weapon::setType(const std::string& type)
{
    type_ = type;
}