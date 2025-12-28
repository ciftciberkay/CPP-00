#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook directory;
    std::string cmmd;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmmd))
            break;
        if (cmmd == "ADD")
            directory.addContact();
        else if (cmmd == "SEARCH")
            directory.searchContact();
        else if (cmmd == "EXIT")
            break;
    }
    return 0;
}