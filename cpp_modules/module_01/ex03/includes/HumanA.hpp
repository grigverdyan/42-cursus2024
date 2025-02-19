#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack();

private:
    std::string name_;
    Weapon& weapon_;
};

#endif // HUMANA_HPP