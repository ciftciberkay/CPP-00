#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _userName;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact();
        ~Contact();

        void    setContact();
        void    displaySummary(int index) const;
        void    displayDetails() const;
};

#endif