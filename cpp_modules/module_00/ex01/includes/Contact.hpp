#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    Contact(std::string firstName = "", 
            std::string lastName = "", 
            std::string nickname = "", 
            std::string phoneNumber = "", 
            std::string darkestSecret = "");

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

private:
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phoneNumber_;
    std::string darkestSecret_;
};

#endif // CONTACT_HPP