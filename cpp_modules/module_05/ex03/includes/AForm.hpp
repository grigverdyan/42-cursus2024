#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <ostream>

// forward declaration
class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const std::string& name, int signGrade, int execGrade);
    virtual ~AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

    std::string getName() const;
    bool getIsSigned() const;;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(const Bureaucrat& executor) const = 0;
    
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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP