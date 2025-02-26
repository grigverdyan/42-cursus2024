#include "RPN.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const std::string& input) 
    : input_(input) 
{}

float RPN::calculate()
{
    processInput();
    return stack_.top();
}

void RPN::processInput() 
{
    if (input_.find_first_not_of("0123456789+-*/ ") != std::string::npos) { 
        throw std::runtime_error("Only numbers, operators and space are accepted in Polish Notation!");
    }

    float operand1;
    float operand2;

    for (std::string::iterator it = input_.begin(); it != input_.end(); ++it) 
    {
        char ch = *it;
        if (std::isdigit(ch)) {
            stack_.push(std::strtof(&ch, NULL));
        }
        else if (std::string("+-/*").find(ch) != std::string::npos) 
        {
            if (stack_.size() < 2) {
                throw NotEnoughNumbers();
            }
            operand2 = stack_.top();
            stack_.pop();
            operand1 = stack_.top();
            stack_.pop();
            performOperation(ch, operand1, operand2);
        }
    }

    if (stack_.size() != 1) {
        throw NotEnoughOperators();
    }
}

void RPN::performOperation(char op, float operand1, float operand2) 
{
    switch (op)
    {
        case '+':
            stack_.push(operand1 + operand2);
            break;
        case '-':
            stack_.push(operand1 - operand2);
            break;
        case '/':
            if (operand2 == 0)
            {
                throw DivisionByZero();
            }
            stack_.push(operand1 / operand2);
            break;
        case '*':
            stack_.push(operand1 * operand2);
            break;
        default:
            break;
    }
}

RPN::RPN(const RPN& other) 
    : input_(other.input_)
    , stack_(other.stack_)
{}

RPN&    RPN::operator=(const RPN &other) 
{
    if (this != &other)
    {
        input_ = other.input_;
        stack_ = other.stack_;
    }
    return *this;
}

RPN::~RPN() {}

const char* RPN::DivisionByZero::what() const throw() 
{
  return "Encountered division by zero!";
}

const char* RPN::NotEnoughNumbers::what() const throw() 
{
  return "Not enough number to perform operation!";
}

const char* RPN::NotEnoughOperators::what() const throw() 
{
  return "Not enough operators to perform operation!";
}