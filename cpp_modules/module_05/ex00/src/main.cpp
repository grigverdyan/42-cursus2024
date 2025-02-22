#include "Bureaucrat.hpp"

#include <iostream>

int main() 
try
{
    Bureaucrat b1("Popo", 3);
    Bureaucrat b2("Boho", 2);
    Bureaucrat b3 = b1;

    b1.decrementGrade(4);
    b1.incrementGrade();
    b2.incrementGrade(1);

    std::cout << b1;
    std::cout << b2;
    b3.decrementGrade(167);

    return 0;

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

