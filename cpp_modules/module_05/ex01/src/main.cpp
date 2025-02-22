#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main() 
try
{
    /* Create a form with grade too high */
	{
        Form form0("2-NDFL", 0, 5);
        std::cout << form0 << std::endl;
	}

	std::cout << "\n --------------------- \n\n";

	/* Create form and sign it without exceptions */
	{
        Bureaucrat mike("Mike", 15);
        Form form("B58", 20, 45);
        std::cout << mike << std::endl;
        std::cout << form << std::endl;
        mike.signForm(form);
        std::cout << form << std::endl;
	}
	
	std::cout << "\n --------------------- \n\n";

	/* Create form and try to sign it but the grade is not enough */
	{
        Bureaucrat jon("Jon", 35);
        Form form2("C_303", 20, 45);
        std::cout << jon << std::endl;
        std::cout << form2 << std::endl;
        jon.signForm(form2);
        std::cout << form2 << std::endl;
	}
	return (0);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

