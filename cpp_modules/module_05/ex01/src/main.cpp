#include "Bureaucrat.hpp"

#include <iostream>

int main() 
try
{
    Bureaucrat b1("Popo", 3);
    Bureaucrat b2("Boho", 2);
    Bureaucrat b3;
    b3 = b1;
    Bureaucrat b4 = b1;

    b1.incrementGrade(1);
    b3.incrementGrade(1);
    b4.decrementGrade(1);

    std::cout << b1;
    return 0;

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

