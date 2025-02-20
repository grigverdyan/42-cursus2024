#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);

public:
    virtual void learnMateria(AMateria* );
    virtual AMateria* createMateria(std::string const& type);

private:
    static const size_t materiaCount_ = 4;
    AMateria* materias_[materiaCount_];
};

#endif