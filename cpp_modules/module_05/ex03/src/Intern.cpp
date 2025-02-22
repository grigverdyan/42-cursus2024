#include "Intern.hpp"

const char* Intern::UndefinedForm::what() const throw()
{
    return "Undefined Form name!";
}

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& /* other */)
{
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    const std::string formTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*formCreators[])(const std::string&) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (size_t i = 0; i < sizeof(formTypes) / sizeof(std::string); ++i) {
        if (formName == formTypes[i]) {
            return (this->*formCreators[i])(target);
        }
    }

    throw UndefinedForm();
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}
}