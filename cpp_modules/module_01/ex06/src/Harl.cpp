#include "Harl.hpp"

#include <iostream>

void Harl::debug()
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. \nI've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    const size_t levelCount = 4;
    void (Harl::*funcPtr[levelCount])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[levelCount] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    size_t i = 0;
    for (; i < levelCount; ++i)
    {
        if (level == levels[i])
        {
           break;
        }
    }

    switch (i)
    {
    case 0:
        (this->*funcPtr[0])();
        std::cout << std::endl;
    case 1:
        (this->*funcPtr[1])();
        std::cout << std::endl;
    case 2:
        (this->*funcPtr[2])();
        std::cout << std::endl;
    case 3:
        (this->*funcPtr[3])();
        std::cout << std::endl;
        break;
    default:
        std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}