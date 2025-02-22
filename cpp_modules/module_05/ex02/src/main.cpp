#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

int main()
try
{
	/* Create the 3 forms and some Bureaucrats */

	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("Morty");
	PresidentialPardonForm pardon("Rick Sanchez");
	Bureaucrat mike("Mike", 150);
	Bureaucrat jon("Jon", 120);
	Bureaucrat steve("Steve", 3);
	
	/* Try to execute forms without being signed */
	{
                std::cout << mike << std::endl;
                std::cout << shrubbery << std::endl;
                std::cout << robotomy << std::endl;
                std::cout << pardon << std::endl;
                mike.executeForm(shrubbery);
                jon.executeForm(shrubbery);
                steve.executeForm(shrubbery);
                mike.executeForm(robotomy);
                mike.executeForm(pardon);
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign form and try to execute without enough grade */
	{
                std::cout << mike << std::endl;
                std::cout << jon << std::endl;
                std::cout << shrubbery << std::endl;
                std::cout << robotomy << std::endl;
                std::cout << pardon << std::endl;
                shrubbery.beSigned(jon);
                mike.executeForm(shrubbery);
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign forms and execute them */
	{
                robotomy.beSigned(steve);
                pardon.beSigned(steve);
                std::cout << shrubbery << std::endl;
                std::cout << robotomy << std::endl;
                std::cout << pardon << std::endl;
                
                std::cout << "\n --------------------- \n\n";
                steve.executeForm(shrubbery);
                std::cout << "\n --------------------- \n\n";
                steve.executeForm(robotomy);
                std::cout << "\n --------------------- \n\n";
                steve.executeForm(pardon);
	}
	
	std::cout << "\n --------------------- \n\n";


	return (0);
}
catch (std::exception &e)
{
        std::cerr << e.what() << std::endl;
}
