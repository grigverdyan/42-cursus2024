#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
    : name_("Zombie")
{}

Zombie::Zombie(std::string name) 
    : name_(name)
{}

Zombie::~Zombie()
{
    std::cout << name_  << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    name_ = name;
}