#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed& other);
    ~Fixed();
    Fixed &operator=(const Fixed& other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int value_;
    static const int bits_ = 8;
};

#endif // FIXED_HPP