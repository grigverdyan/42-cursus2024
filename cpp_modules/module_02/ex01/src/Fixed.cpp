#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed() 
    : value_(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    value_ = value << bits_;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    value_ = static_cast<int>(roundf(value * (1 << bits_)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value_ = other.value_;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value_;
}

void Fixed::setRawBits(int const raw)
{
    value_ = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(value_) / (1 << bits_);
}

int Fixed::toInt(void) const
{
    return value_ >> bits_;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
