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

        void    setPerson();
        void    showInfo(int index) const;
        void    showDetails() const;
};

#endif