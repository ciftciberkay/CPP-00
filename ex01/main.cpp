#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook phoneBook;
	std::string command;
	
	while (true)
    {
		std::cout << "\nEnter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (std::cin.eof())
        {
			std::cout << std::endl << "Exiting PhoneBook. Goodbye!" << std::endl;
			break;
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
			std::cout << "Exiting PhoneBook. Contacts will be lost forever!" << std::endl;
			break;
		}
		else
        {
			std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
		}
	}
	return 0;
}