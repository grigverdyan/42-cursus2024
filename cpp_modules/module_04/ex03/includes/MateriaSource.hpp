#ifndef MATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);

public:
    virtual void learnMateria(AMateria* ) override;
    virtual AMateria* createMateria(std::string const& type) override;

private:
    static const size_t materiaCount_ = 4;
    AMateria* materias_[materiaCount_];
};

#endif