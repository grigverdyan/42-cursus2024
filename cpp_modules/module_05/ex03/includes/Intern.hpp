#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    AForm*	makeShrubberyCreationForm(const std::string) const;
	AForm*	makePresidentialPardonForm(const std::string) const;
	AForm*	makeRobotomyRequestForm(const std::string) const;
	int		getFormInex(const std::string formName) const;

public:
    struct	UndefinedForm: public std::exception
    {
        const char *what() const throw();
    };
};

typedef	AForm*(Intern::*FormMakers)(std::string) const;

#endif // INTERN_HPP