#include "Brain.hpp"

#include <string>
#include <iostream>

Brain::Brain()
{
    for (size_t i = 0; i < 100; ++i)
    {
        ideas_[i] = "Idea #" + i;
    }
    std::cout << "Brain default constructor called!" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (size_t i = 0; i < 100; ++i)
    {
        ideas_[i] = other.ideas_[i];
    }
    std::cout << "Brain copy constructor called!" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 100; ++i)
        {
            ideas_[i] = other.ideas_[i];
        }
    }
    std::cout << "Brain assignment operator called!" << std::endl;
    return *this;
}
