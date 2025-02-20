#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria()
    :type_("Abstract Materia")
{}

AMateria::AMateria(const std::string& type)
    : type_(type)
{}

AMateria::AMateria(const AMateria& /* other */)
{}

AMateria& AMateria::operator=(const AMateria& /* other */)
{
    return *this;
}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const
{
    return type_;
}

void AMateria::use(ICharacter& /* target */)
{
    std::cout << "AMateria use function call!" << std::endl;
}