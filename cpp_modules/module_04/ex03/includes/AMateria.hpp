#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <string>

class AMateria
{
public:
    AMateria();
    Amateria(const AMateria& other);

    std::string const & getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICHaracter& target);

protected:

};

#endif // AMATERIA_HPP