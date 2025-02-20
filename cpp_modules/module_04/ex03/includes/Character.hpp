#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character();
    Character(std::string name);
    virtual ~Character();
    Character(const Character& other);
    Character& operator=(const Character& other);

    virtual const std::string& getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

private:
    static const size_t slotCount_= 4;
    AMateria* slots_[slotCount_];
    std::string name_;
};

#endif