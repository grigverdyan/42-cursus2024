#include "RPN.hpp"

#include <iostream>
#include <exception>

int main(int argc, char *argv[]) 
{
    std::string input;

    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"polish notation\"" << std::endl;
        return 1;
    }

    input = argv[1];
    try 
    {
        RPN rpn(input);
        float result = rpn.calculate();
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}