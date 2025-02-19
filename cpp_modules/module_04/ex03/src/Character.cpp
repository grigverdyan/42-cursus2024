#include "Character.hpp"
#include "IceMateria.hpp"
#include "CureMateria.hpp"

Character::Character()
    : ICharacter()
    , name_("")
{}

Character::Character(std::string name)
    : ICharacter()
    , name_(name)
{}

Character::~Character()
{
    for (size_t i = 0; i < slotCount_; ++i)
    {
        if (slots_[i])
        {
            delete slots_[i];
        }
    }
}

Character::Character(const Character& other)
{
    for (size_t i = 0; i < slotCount_; ++i)
    {
        if (slots_[i])
        {
            delete slots_[i];
        }
    }

    for (size_t i = 0; i < slotCount_; ++i)
    {
        if (slots_[i]->getType() == "ice")
        {
            slots_[i] = new IceMateria(other.slots_[i]);           
        }
        else if (slots_[i]->getType() == "cure")
        {
            slots_[i] = new CureMateria(other.slots_[i]);
        }
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < slotCount_; ++i)
        {
            if (slots_[i])
            {
                delete slots_[i];
            }
        }

        for (size_t i = 0; i < slotCount_; ++i)
        {
            if (slots_[i]->getType() == "ice")
            {
                slots_[i] = new IceMateria(other.slots_[i]);           
            }
            else if (slots_[i]->getType() == "cure")
            {
                slots_[i] = new CureMateria(other.slots_[i]);
            }
        }
    }
    return *this;
}

const std::string& Character::getName() const
{
    return name_;
}

void Character::equip(AMateria* m)
{
    if (m)
    {
        for (size_t i = 0; i < slotCount_; ++i)
        {
            if (!slots_[i])
            {
                slots_[i] = m;
            }
        }
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (slots_[idx])
    {
        slots_[idx]->use(target);
    }
}

void Character::unequip(int idx)
{
    slots_[idx] = NULL;

    // AMateria *m = NULL;
    // if (slots_[idx])
    // {
    //     m = slots[idx];
    //     slots[idx] = NULL;
    // }
    // return m;
}

