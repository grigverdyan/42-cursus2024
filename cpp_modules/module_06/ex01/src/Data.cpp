#include <iostream>

#include "Data.hpp"

Data::Data() 
	: number_(0)
{}

Data::Data(int number) 
	: number_(number) 
{}

Data::~Data() {}

Data::Data(const Data& other) 
	: number_(other.number_) 
{}

Data& Data::operator=(const Data& other)
{
    if (this != &other) {
        number_ = other.number_;
    }
    return *this;
}

int Data::getNumber() const
{
    return number_;
}

std::ostream& operator<<(std::ostream& out, const Data& other)
{
    out << "Data: " << other.getNumber();
    return out;
}