#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

Bureaucrat::Bureaucrat()
    : name_("Default")
    , grade_(LOWEST_GRADE)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name)
{
    if (grade > LOWEST_GRADE)
    {
        throw GradeTooLowException();
    }
    if (grade < HIGHEST_GRADE)
    {
        throw GradeTooHighException();
    }
    grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_)
    , grade_(other.grade_)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        const_cast<std::string&>(name_) = other.name_;
        grade_ = other.grade_;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

void Bureaucrat::incrementGrade(int i)
{
    if (grade_ - i < HIGHEST_GRADE)
    {
        throw GradeTooHighException();
    }
    grade_ -= i;
}

void Bureaucrat::decrementGrade(int i)
{
    if (grade_ + i > LOWEST_GRADE)
    {
        throw GradeTooLowException();
    }
    grade_ += i;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat " << name_ << " signed form " << form.getName() << "." << std::endl;
    }
    catch (const std::exception& e)
    {
		std::cout << "Bureaucrat " << name_ <<  " couldn't sign form " << form.getName() << ", because " << std::flush;
		std::cout << e.what() << std::endl;   
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat's grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat's grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade() << "." << std::endl;
    return os;
}