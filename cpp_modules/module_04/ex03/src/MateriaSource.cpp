#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

MateriaSource::MateriaSource() 
{
    for (size_t i = 0; i < materiaCount_; ++i)
    {
        materias_[i] = NULL;
    }
}

MateriaSource::~MateriaSource() 
{
    for (size_t i = 0; i < materiaCount_; ++i)
    {
        if (materias_[i])
        {
            delete materias_[i];
            materias_[i] = NULL;
        }
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (size_t i = 0; i < materiaCount_; ++i)
    {
        if (other.materias_[i] == NULL)
        {
            materias_[i] = NULL;
            continue;
        }
        materias_[i] = other.materias_[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) 
{
    if (this != &other)
    {
        for (size_t i = 0; i < materiaCount_; ++i)
        {
            if (materias_[i])
            {
                delete materias_[i];
                materias_[i] = NULL;
            }
        }

        for (size_t i = 0; i < materiaCount_; ++i)
        {
            if (other.materias_[i] == NULL)
            {
                materias_[i] = NULL;
                continue;
            }
            materias_[i] = other.materias_[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    bool isFull = true;
    for (size_t i = 0; i < materiaCount_; ++i)
    {
        if (!materias_[i])
        {
            isFull = false;
            materias_[i] = m;
            return;
        }
    }
    if (isFull)
    {
        std::cout << "MateriaSource is full!" << std::endl;
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = static_cast<int>(materiaCount_) - 1; i >= 0; --i)
    {
        if (materias_[i] && materias_[i]->getType() == type)
        {
            return materias_[i]->clone();
        }
    }

    std::cout << "Materia not found!" << std::endl;
    return NULL;
}
