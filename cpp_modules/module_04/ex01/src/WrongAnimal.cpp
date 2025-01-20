#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal()
    : type_("Animal")
{
    std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    : type_(other.type_)
{
    std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        type_ = other.type_;
    }
    std::cout << "WrongAnimal assignment operator called!" << std::endl;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return type_;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sounds..." << std::endl;
}