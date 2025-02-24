#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <exception>

class RPN 
{
public:
    explicit RPN(const std::string& input);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    float   calculate();

public:
    class DivisionByZero : public std::exception 
    {
        const char *what() const throw();
    };

    class NotEnoughNumbers : public std::exception 
    {
        const char *what() const throw();
    };

    class NotEnoughOperators : public std::exception 
    {
        const char *what() const throw();
    };

private:
    RPN();

    void    processInput();
    void    performOperation(char op, float operand1, float operand2);

private:
    std::string input_;
    std::stack<float> stack_;
};

#endif // RPN_HPP