#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure()
    : AMateria("cure")
{}

Cure::Cure(const std::string& type)
    : AMateria(type)
{}

Cure::~Cure() {}

Cure::Cure(const Cure& other)
    : AMateria(other)
{}

Cure& Cure::operator=(const Cure& other)
{
    AMateria::operator=(other);
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure();
}
