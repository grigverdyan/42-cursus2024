#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

AForm::AForm()
    : name_("Default")
    , isSigned_(false)
    , signGrade_()
    , execGrade_()
{}

AForm::~AForm()
{}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : name_(name)
    , isSigned_(false)
    , signGrade_(signGrade)
    , execGrade_(execGrade)
{}

AForm::AForm(const AForm& other)
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

AForm& AForm::operator=(const AForm& other)
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

std::string AForm::getName() const
{
    return name_;
}

bool AForm::getIsSigned() const
{
    return isSigned_;
}

int AForm::getSignGrade() const 
{
    return signGrade_;
}

int AForm::getExecGrade() const 
{
    return execGrade_;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
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

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form's grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form's grade is too low!";
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (isSigned_)
    {
        throw std::runtime_error("Form is already signed!");
    }
    if (execGrade_ < executor.getGrade())
    {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName() << std::endl
       << "Signed grade: " << form.getSignGrade() << std::endl
       << "Executed grade: " << form.getExecGrade() << std::endl
       << "Form is signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;       
    
    return os;
}
