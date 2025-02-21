#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice()
    : AMateria("ice")
{}

Ice::Ice(const std::string& type)
    : AMateria(type)
{}

Ice::~Ice() {}

Ice::Ice(const Ice& other)
    : AMateria(other)
{}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}
