#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

Contact::Contact() {}
Contact::~Contact() {}

static std::string getInput(std::string prompt)
{
    std::string input = "";
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            exit(0);
        if (!input.empty())
            break;
        std::cout << "Field cannot be empty." << std::endl;
    }
    return input;
}

void Contact::setContact()
{
    _firstName = getInput("Enter First Name: ");
    _lastName = getInput("Enter Last Name: ");
    _userName = getInput("Enter Nickname: ");
    _phoneNumber = getInput("Enter Phone Number: ");
    _darkestSecret = getInput("Enter Darkest Secret: ");
}

static std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displaySummary(int index) const
{
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << truncate(_firstName);
    std::cout << "|" << std::setw(10) << truncate(_lastName);
    std::cout << "|" << std::setw(10) << truncate(_userName) << "|" << std::endl;
}

void Contact::displayDetails() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _userName << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}
