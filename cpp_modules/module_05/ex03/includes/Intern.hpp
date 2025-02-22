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
    AForm*	createShrubberyCreationForm(const std::string& target) const;
	AForm*	createPresidentialPardonForm(const std::string& target) const;
	AForm*	createRobotomyRequestForm(const std::string& target) const;

public:
    struct	UndefinedForm: public std::exception
    {
        const char *what() const throw();
    };
};

typedef	AForm*(Intern::*FormCreators)(const std::string& ) const;

#endif // INTERN_HPP