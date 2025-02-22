#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>

int main()
try
{
    Intern		bob;
	AForm		*form;
	Bureaucrat	karen("Karen", 50);

	try
	{
		form = bob.makeForm("robotomy request", "Alice");
		delete form;

		form = bob.makeForm("shrubbery creation", "Charlie");
		delete form;

		form = bob.makeForm("presidential pardon", "David");
		delete form;
		
		form = bob.makeForm("random request", "Manon");
		delete form;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;

	form = bob.makeForm("shrubbery creation", "Fred");
	// form->beSigned(karen);
	karen.signForm(*form);
	karen.executeForm(*form);
	delete form;

	std::cout << "------------------------------------" << std::endl;

	form = bob.makeForm("presidential pardon", "Georgia");
	karen.signForm(*form);
	karen.executeForm(*form);

	/* Increment Karen's grade and execute form again */
	karen.incrementGrade(47);
	karen.executeForm(*form);


	delete form;
        
	return 0;

}
catch (std::exception &e)
{
    std::cerr << e.what() << std::endl;
}
