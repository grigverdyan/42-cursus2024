#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character();
    virtual ~Character();
    Character(const Character& other);
    Character& operator=(const Character& other);

    virtual const std::string& getName() const override;
    virtual void equip(AMateria* m) override;
    virtual void unequip(int idx) override;
    virtual void use(int idx, ICharacter& target) override;
};

#endif