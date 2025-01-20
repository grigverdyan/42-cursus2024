#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat()
    : WrongAnimal()
{
    type_ = "WrongCat";
    std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other)
{
    type_ = other.type_;
    std::cout << "WrongCat copy constructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        type_ = other.type_;
    }
    std::cout << "WrongCat assignment operator called!" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongMeow!" << std::endl;
}