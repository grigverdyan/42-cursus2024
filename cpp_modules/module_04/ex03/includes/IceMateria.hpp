#ifndef ICEMATERIA_HPP
#define ICEMATERIA_HPP

#include "AMateria.hpp"

class IceMateria : public AMateria
{
public:
    IceMateria();
    IceMateria(const std::string& type);

    IceMateria(const IceMateria& other);
    IceMateria& operator=(const IceMateria& other);
    virtual ~IceMateria();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif // ICEMATERIA_HPP