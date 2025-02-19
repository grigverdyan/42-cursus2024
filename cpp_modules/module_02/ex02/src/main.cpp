#include <iostream>

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;

    // Disabled implicit conversions
    // std::cout << "Experiment\n\n\n";
    // Fixed c;
    // c = 7.13;
    // std::cout << c.toInt();
    
    return 0;
}