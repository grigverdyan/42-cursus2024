#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed() 
    : value_(0)
{}

Fixed::Fixed(const int value)
{
    value_ = value << bits_;
}

Fixed::Fixed(const float value)
{
    value_ = static_cast<int>(roundf(value * (1 << bits_)));
}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed& other) 
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
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

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.value_ = this->value_ + other.value_;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.value_ = this->value_ - other.value_;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.value_ = (this->value_ * other.value_) >> bits_;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    if (other.value_ == 0)
    {
        std::cerr << "Error: division by zero" << std::endl;
    }
    else
    {
        result.value_ = (this->value_ << bits_) / other.value_;
    }
    return result;
}

bool Fixed::operator<(const Fixed& other) const
{
    return value_ < other.value_;
}

bool Fixed::operator>(const Fixed& other) const
{
    return value_ > other.value_;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return value_ <= other.value_;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return value_ >= other.value_;
}

bool Fixed::operator==(const Fixed& other) const
{
    return value_ == other.value_;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return value_ != other.value_;
}

// prefix increment
Fixed& Fixed::operator++()
{
    ++value_;
    return *this;
}

// postfix increment
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

// prefix decrement
Fixed& Fixed::operator--()
{
    --value_;
    return *this;
}

// postfix decrement
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
