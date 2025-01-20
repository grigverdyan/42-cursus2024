#include "Dog.hpp"

#include <iostream>

Dog::Dog()
    : Animal()
{
    type_ = "Dog";
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(other)
{
    type_ = other.type_;
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        type_ = other.type_;
    }
    std::cout << "Dog assignment operator called!" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark bark!" << std::endl;
}