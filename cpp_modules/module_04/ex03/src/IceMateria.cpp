#include "IceMateria.hpp"

IceMateria::IceMateria()
    : AMateria()
    , type_("ice")
{}

IceMateria::IceMateria(const std::string& type)
    : AMateria(type)
{}

IceMateria::~IceMateria() {}

IceMateria::IceMateria(const IceMateria& other)
    : AMateria(other)
{}

IceMateria& IceMateria::operator=(const IceMateria& other)
{
    AMateria::operator=(other);
    return *this;
}

void IceMateria::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* IceMateria::clone() const
{
    return new IceMateria();
}
