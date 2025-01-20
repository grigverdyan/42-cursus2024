#include "Dog.hpp"

#include <iostream>

Dog::Dog()
    : Animal()
{
    type_ = "Dog";
    std::cout << "Dog default constructor called!" << std::endl;
    brain_ = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor called!" << std::endl;
    delete brain_;
}

Dog::Dog(const Dog& other)
    : Animal(other)
{
    type_ = other.type_;
    delete brain_;
    brain_ = new Brain(*other.brain_);
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        type_ = other.type_;
        delete brain_;
        brain_ = new Brain(*other.brain_);
    }
    std::cout << "Dog assignment operator called!" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark bark!" << std::endl;
}