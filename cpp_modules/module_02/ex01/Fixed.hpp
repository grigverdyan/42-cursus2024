#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);
    ~Fixed();
    Fixed& operator=(const Fixed& other);

    float toFloat(void) const;
    int toInt(void) const;  
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int value_;
    static const int bits_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP