#include "RPN.hpp"

#include <iostream>
#include <exception>

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"polish notation\"" << std::endl;
        return 1;
    }

    try 
    {
        RPN rpn(argv[1]);
        float result = rpn.calculate();
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: "<< e.what() << std::endl;
    }

    return 0;
}