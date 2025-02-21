#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

Character::Character()
    : ICharacter()
    , name_("")
{
    for (size_t i = 0; i < slotCount_; ++i)
    {
        slots_[i] = NULL;
    }
}

Character::Character(std::string name)
    : ICharacter()
    , name_(name)
{
    for (size_t i = 0; i < slotCount_; ++i)
    {
        slots_[i] = NULL;
    }
}

Character::~Character()
{
    for (size_t i = 0; i < slotCount_; ++i)
    {
        if (slots_[i] != NULL)
        {
            std::cout << "Character " << slots_[i]->getType() << " destroyed." << std::endl;
            delete slots_[i];
            slots_[i] = NULL;
        }
    }
}

Character::Character(const Character& other)
    : ICharacter(other)
    , name_(other.name_)
{
    for (size_t i = 0; i < slotCount_; ++i)
    {
        if (other.slots_[i] == NULL)
        {
            slots_[i] = NULL;
            continue;
        }
        slots_[i] = other.slots_[i]->clone();
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name_ = other.name_;
    
        for (size_t i = 0; i < slotCount_; ++i)
        {
            if (slots_[i])
            {
                delete slots_[i];
                slots_[i] = NULL;
            }
        }

        for (size_t i = 0; i < slotCount_; ++i)
        {
            if (other.slots_[i] == NULL)
            {
                slots_[i] = NULL;
                continue;
            }
            slots_[i] = other.slots_[i]->clone();
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
    if (!m)
    {
        std::cout << "Invalid materia pointer" << std::endl;
        return;
    }
    for (size_t i = 0; i < slotCount_; ++i)
    {
        if (slots_[i] == m)
        {
            std::cout << "Materia " << m->getType() << " is already equipped for character " << name_ << "!" << std::endl;
            return;
        }
    }

    for (size_t i = 0; i < slotCount_; ++i)
    {
        if (!slots_[i])
        {
            slots_[i] = m;
            return;
        }
    }
    std::cout << "Character: " << name_ << "'s inventory is full!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= static_cast<int>(slotCount_))
    {
        std::cout << "Invalid index: " << idx << std::endl;
        return;
    }
    if (!slots_[idx])
    {
        std::cout << "No materia in slot " << idx << std::endl;
        return;
    }
    slots_[idx]->use(target);
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= static_cast<int>(slotCount_))
    {
        std::cout << "Invalid index: " << idx << std::endl;
        return;
    }
    if (!slots_[idx])
    {
        std::cout << "No materia in slot " << idx << std::endl;
        return;
    }
    std::cout << "Unequipped " << slots_[idx]->getType() << " from " << name_ << "'s inventory at index " << idx << std::endl;
    slots_[idx] = NULL;
}

