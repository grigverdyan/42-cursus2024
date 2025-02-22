#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

Form::Form()
    : name_("Default")
    , isSigned_(false)
    , signGrade_()
    , execGrade_()
{}

Form::~Form()
{}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : name_(name)
    , isSigned_(false)
    , signGrade_(signGrade)
    , execGrade_(execGrade)
{}

Form::Form(const Form& other)
    : name_(other.name_)
    , isSigned_(other.isSigned_)
    , signGrade_(other.signGrade_)
    , execGrade_(other.execGrade_)
{
    if (signGrade_ > LOWEST_GRADE || execGrade_ > LOWEST_GRADE)
    {
        throw GradeTooLowException();
    }
    if (signGrade_ < HIGHEST_GRADE || execGrade_ < HIGHEST_GRADE)
    {
        throw GradeTooHighException();
    }
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        const_cast<std::string&>(name_) = other.name_;
        const_cast<int&>(signGrade_) = other.signGrade_;
        const_cast<int&>(execGrade_) = other.execGrade_;
        isSigned_ = other.isSigned_;
    }
    return *this;
}

std::string Form::getName() const
{
    return name_;
}

bool Form::getIsSigned() const
{
    return isSigned_;
}

int Form::getSignGrade() const 
{
    return signGrade_;
}

int Form::getExecGrade() const 
{
    return execGrade_;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (signGrade_ >= bureaucrat.getGrade())
    {
        isSigned_ = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form's grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form's grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << std::endl
       << "Signed grade: " << form.getSignGrade() << std::endl
       << "Executed grade: " << form.getExecGrade() << std::endl
       << "Form is signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;       
    
    return os;
}
