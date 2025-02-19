#include "CureMateria.hpp"

CureMateria::CureMateria()
    : AMateria()
    , type_("cure")
{}

CureMateria::CureMateria(const std::string& type)
    : AMateria(type)
{}

CureMateria::~CureMateria() {}

CureMateria::CureMateria(const CureMateria& other)
    : AMateria(other)
{}

CureMateria& CureMateria::operator=(const CureMateria& other)
{
    AMateria::operator=(other);
    return *this;
}

void CureMateria::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* CureMateria::clone() const
{
    return new CureMateria();
}
