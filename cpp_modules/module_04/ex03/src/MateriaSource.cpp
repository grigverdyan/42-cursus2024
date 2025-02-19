#include "MateriaSource.hpp"
#include "IceMateria.hpp"
#include "CureMateria.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::~MateriaSource() 
{
    for (size_t i = 0; i < materiaCount_; ++i)
    {
        if (materias_[i])
        {
            delete materias_[i];
        }
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) 
{
    for (size_t i = 0; i < materiaCount_; ++i)
    {
        if (materias_[i])
        {
            delete materias_[i];
        }
    }

    for (size_t i = 0; i < materiaCount_; ++i)
    {
        if (materias_[i]->getType() == "ice")
        {
            materias_[i] = new IceMateria(other.materias_[i]);        
        }
        else if (materias_[i]->getType() == "cure")
        {
            materias_[i] = new IceMateria(other.materias_[i]);        
        }
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
            }
        }

        for (size_t i = 0; i < materiaCount_; ++i)
        {
            if (materias_[i]->getType() == "ice")
            {
                materias_[i] = new IceMateria(other.materias_[i]);        
            }
            else if (materias_[i]->getType() == "cure")
            {
                materias_[i] = new IceMateria(other.materias_[i]);        
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (size_t i = 0; i < materiaCount_; ++i)
    {
        if (!materias_[i])
        {
            materias_[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    AMateria* newMateria = NULL;
    for (size_t i = materiaCount_ - 1; i >= 0; --i)
    {
        if (materias_[i] && materias_[i].getType() == type)
        {
            newMateria = materias_[i];
        }
    }
    return newMateria;
}
