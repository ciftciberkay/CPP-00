#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

PhoneBook::PhoneBook() : _contactCount(0), _nextContactIndex(0) {
}

PhoneBook::~PhoneBook() {
}

std::string PhoneBook::_getInput(std::string prompt) const {
	std::string input = "";
	while (!std::cin.eof() && input.empty()) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << "Field cannot be empty. Please try again." << std::endl;
		}
	}
	return input;
}

void PhoneBook::addContact() {
	Contact newContact;
	std::string input;

	input = this->_getInput("Enter first name: ");
	if (std::cin.eof()) return;
	newContact.setFirstName(input);
	input = this->_getInput("Enter last name: ");
	if (std::cin.eof()) return;
	newContact.setLastName(input);
	input = this->_getInput("Enter nickname: ");
	if (std::cin.eof()) return;
	newContact.setNickname(input);
	input = this->_getInput("Enter phone number: ");
	if (std::cin.eof()) return;
	newContact.setPhoneNumber(input);
	input = this->_getInput("Enter darkest secret: ");
	if (std::cin.eof()) return;
	newContact.setDarkestSecret(input);
	this->_contacts[this->_nextContactIndex] = newContact;
	this->_nextContactIndex = (this->_nextContactIndex + 1) % 8;
	
	if (this->_contactCount < 8) {
		this->_contactCount++;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

std::string PhoneBook::_truncate(std::string str) const {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

int PhoneBook::_getIndexInput() const {
	int index = -1;
	std::string line;
	bool isValid = false;

	while (!std::cin.eof() && !isValid) {
		std::cout << "Enter the index of the contact to display: ";
		std::getline(std::cin, line);
		if (std::cin.eof()) return -1;
		std::stringstream ss(line);
		if ((ss >> index) && ss.eof() && index >= 0 && index < this->_contactCount) {
			isValid = true;
		}
		else
		{
			std::cout << "Invalid index. Please enter a number between 0 and "
					  << (this->_contactCount - 1) << "." << std::endl;
		}
	}
	return index;
}

void PhoneBook::searchContact() const {
	if (this->_contactCount == 0)
	{
		std::cout << "PhoneBook is empty. Use ADD to add new contacts." << std::endl;
		return;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "Index"
			  << "|" << std::setw(10) << std::right << "First Name"
			  << "|" << std::setw(10) << std::right << "Last Name"
			  << "|" << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->_contactCount; ++i)
	{
		std::cout << "|" << std::setw(10) << std::right << i
				  << "|" << std::setw(10) << std::right << this->_truncate(this->_contacts[i].getFirstName())
				  << "|" << std::setw(10) << std::right << this->_truncate(this->_contacts[i].getLastName())
				  << "|" << std::setw(10) << std::right << this->_truncate(this->_contacts[i].getNickname())
				  << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	int index = this->_getIndexInput();
	if (std::cin.eof() || index == -1)
	{
		return;
	}
	std::cout << std::endl;
	std::cout << "Displaying contact #" << index << ":" << std::endl;
	std::cout << "First Name:     " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name:      " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:       " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number:   " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}
