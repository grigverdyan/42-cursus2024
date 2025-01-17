#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

PhoneBook::PhoneBook()
    : contactCount_(0)
    , index_(0)
{}

void PhoneBook::addContact()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    firstName = getContactField("First name");
    lastName = getContactField("Last name");
    nickname = getContactField("Nickname");
    phoneNumber = getContactField("Phone number");
    darkestSecret = getContactField("Darkest secret");

    if (firstName.empty() || lastName.empty() || nickname.empty()
        || phoneNumber.empty() || darkestSecret.empty())
    {
        std::cout << "Contact not added. All fields must be filled." << std::endl;
        return;
    }

    contacts_[index_] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    if (contactCount_ < MAX_CONTACTS)
    {
        ++contactCount_;
    }
    // If the contactCount_ is equal to MAX_CONTACTS, the oldest contact will be overwritten
    index_ = (index_ + 1) % MAX_CONTACTS;
}

void    PhoneBook::searchContact() const
{
    if (contactCount_ == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    size_t const fieldWidth = 10;

    std::cout << std::setw(fieldWidth) << std::right << "Index" << "|"
              << std::setw(fieldWidth) << std::right << "First Name" << "|"
              << std::setw(fieldWidth) << std::right << "Last Name" << "|"
              << std::setw(fieldWidth) << std::right << "Nickname" << std::endl;
    std::cout << std::setw(fieldWidth * 4) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

    for (size_t i = 0; i < contactCount_; ++i)
    {
        std::cout << std::setw(fieldWidth) << std::right <<  i << "|";
        std::cout << std::setw(fieldWidth) << std::right << getTruncatedField(contacts_[i].getFirstName()) << "|";
        std::cout << std::setw(fieldWidth) << std::right << getTruncatedField(contacts_[i].getLastName()) << "|";
        std::cout << std::setw(fieldWidth) << std::right << getTruncatedField(contacts_[i].getNickname()) << std::endl;
    }

    size_t index;
    std::cout << "Enter the index of the contact you want to see: ";
    std::cin >> index;
    // Validate input of index
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid index." << std::endl;
        return;
    }

    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }

    if (!isContactIndexValid(index))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cout << "First name: " << contacts_[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts_[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts_[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts_[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts_[index].getDarkestSecret() << std::endl;
}

bool PhoneBook::isContactIndexValid(size_t index) const
{
    return index < contactCount_;
}

std::string PhoneBook::getContactField(const std::string& fieldInfo) const
{
    std::string field;

    while (field.empty())
    {
        std::cout << fieldInfo << ": ";
        std::getline(std::cin, field);

        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
    }
    return field;
}

std::string PhoneBook::getTruncatedField(const std::string& field) const
{
    std::string truncatedField;

    if (field.size() > 10)
    {
        truncatedField = field.substr(0, 9);
        truncatedField += ".";
    }
    else
    {
        truncatedField = field;
    }
    return truncatedField;
}