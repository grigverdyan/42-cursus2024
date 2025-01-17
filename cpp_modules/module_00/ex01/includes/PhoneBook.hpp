#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();

    void addContact();
    void searchContact() const;

private:
    bool isContactIndexValid(size_t index) const;
    std::string getContactField(const std::string& fieldInfo) const;
    std::string getTruncatedField(const std::string& field) const;

private:
    static const size_t MAX_CONTACTS = 8;

    size_t contactCount_;
    size_t index_;
    Contact contacts_[MAX_CONTACTS];
};

#endif // PHONEBOOK_HPP