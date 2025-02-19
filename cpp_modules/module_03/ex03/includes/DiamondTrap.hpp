#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    virtual ~DiamondTrap();
    DiamondTrap& operator=(const DiamondTrap& other);

    void whoAmI();
    using ScavTrap::attack;
private:
    std::string name_;
};

#endif // DIAMONDTRAP_HPP