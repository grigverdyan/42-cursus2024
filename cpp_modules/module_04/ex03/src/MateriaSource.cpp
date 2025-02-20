#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

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
            Ice* iceMateria = dynamic_cast<Ice*>(other.materias_[i]);
            if (iceMateria)
            {
                materias_[i] = new Ice(*iceMateria);
            }
        }
        else if (materias_[i]->getType() == "cure")
        {
            Cure* cureMateria = dynamic_cast<Cure*>(other.materias_[i]);
            if (cureMateria)
            {
                materias_[i] = new Cure(*cureMateria);
            }            
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
                Ice* iceMateria = dynamic_cast<Ice*>(other.materias_[i]);
                if (iceMateria)
                {
                    materias_[i] = new Ice(*iceMateria);
                }
            }
            else if (materias_[i]->getType() == "cure")
            {
                Cure* cureMateria = dynamic_cast<Cure*>(other.materias_[i]);
                if (cureMateria)
                {
                    materias_[i] = new Cure(*cureMateria);
                }            
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
    for (size_t i = materiaCount_ - 1; i != 0; --i)
    {
        if (materias_[i] && materias_[i]->getType() == type)
        {
            newMateria = materias_[i];
        }
    }
    return newMateria;
}
