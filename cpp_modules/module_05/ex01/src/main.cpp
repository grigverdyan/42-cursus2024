#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main() 
try
{
    Bureaucrat b1("Popo", 3);
    Bureaucrat b2("Boho", 2);

    Form    f1("2-NDFL", 2, 3);

    b1.signForm(f1);

    return 0;

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

