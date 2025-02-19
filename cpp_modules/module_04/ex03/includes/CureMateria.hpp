#ifndef CUREMATERIA_HPP
#define CUREMATERIA_HPP

#include "AMateria.hpp"

class CureMateria : public AMateria
{
public:
    CureMateria();
    CureMateria(const std::string& type);

    CureMateria(const CureMateria& other);
    CureMateria& operator=(const CureMateria& other);
    virtual ~CureMateria();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif // CUREMATERIA_HPP