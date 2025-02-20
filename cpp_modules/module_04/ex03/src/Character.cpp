#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

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
            Ice* iceMateria = dynamic_cast<Ice*>(other.slots_[i]);
            if (iceMateria)
            {
                slots_[i] = new Ice(*iceMateria);
            }
        }
        else if (slots_[i]->getType() == "cure")
        {
            Cure* cureMateria = dynamic_cast<Cure*>(other.slots_[i]);
            if (cureMateria)
            {
                slots_[i] = new Cure(*cureMateria);
            }            
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
                Ice* iceMateria = dynamic_cast<Ice*>(other.slots_[i]);
                if (iceMateria)
                {
                    slots_[i] = new Ice(*iceMateria);
                }
            }
            else if (slots_[i]->getType() == "cure")
            {
                Cure* cureMateria = dynamic_cast<Cure*>(other.slots_[i]);
                if (cureMateria)
                {
                    slots_[i] = new Cure(*cureMateria);
                }            
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
    if (idx >= 0 && idx < static_cast<int>(slotCount_) && slots_[idx])
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

