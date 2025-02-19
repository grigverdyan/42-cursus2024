#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#include <ostream>

class Point
{
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    ~Point();
    Point& operator=(const Point& other);

    const Fixed getX() const;
    const Fixed getY() const;

private:
    const Fixed x_;
    const Fixed y_;
};

std::ostream& operator<<(std::ostream &o, const Point& point);

#endif // POINT_HPP