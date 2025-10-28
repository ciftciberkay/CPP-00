#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	Contact _contacts[8];
	int     _contactCount;
	int     _nextContactIndex;

	std::string _truncate(std::string str) const;
	std::string _getInput(std::string prompt) const;
	int         _getIndexInput() const;

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact() const;
};

#endif