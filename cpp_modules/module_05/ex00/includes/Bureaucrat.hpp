#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grede);
   
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade(int i);
    void decrementGrade(int i);

public:
    /* Exception classes */
    struct GradeTooHighException : public std::exception
    {
        virtual const char* what() const throw();
    };

    struct GradeTooLowException : public std::exception
    {
        virtual const char* what() const throw();
    };

private:
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;

    const std::string name_;
    int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP