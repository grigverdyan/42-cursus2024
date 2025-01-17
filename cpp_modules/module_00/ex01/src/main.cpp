#include <iostream>

#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        std::cout << "The " << argv[0] << " program does not accept any arguments." << std::endl;
    }

    std::string command;
    PhoneBook phoneBook;
    std::cout << "This is an 80s Phone Book." << std::endl;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }

        // Convert command to uppercase
        for (size_t i = 0; i < command.size(); ++i)
        {
            command[i] = std::toupper(command[i]);
        }

        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}