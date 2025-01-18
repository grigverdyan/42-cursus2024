#include "Point.hpp"


Point::Point()
    : x_(0)
    , y_(0)
{}

Point::Point(const float x, const float y)
    : x_(x)
    , y_(y)
{}

Point::Point(const Point& other)
{
    *this = other;
}

Point::~Point()
{}

Point& Point::operator=(const Point& other)
{
    if (this == &other)
        return *this;
    const_cast<Fixed&>(x_) = other.getX();
    const_cast<Fixed&>(y_) = other.getY();
    return *this;
}

const Fixed Point::getX() const
{
    return x_;
}

const Fixed Point::getY() const
{
    return y_;
}

std::ostream& operator<<(std::ostream &o, const Point& point)
{
    o << "(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
    return o;
}