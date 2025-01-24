#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <ostream>

class Form
{
public:
    Form();
    Form(const std::string& name, int signGrade, int execGrade);
    ~Form();
    Form(const Form& other);
    Form& operator=(const Form& other);

    std::string getName() const;
    bool getIsSigned() const;;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);
    
public:
    struct GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };

    struct GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };

private:
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;

    const std::string   name_;
    bool                isSigned_;
    const int           signGrade_;
    const int           execGrade_;
    
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP