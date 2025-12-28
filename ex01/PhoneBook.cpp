#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : _index(0), _count(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
    _contacts[_index].setPerson();
    _index = (_index + 1) % 8;
    if (_count < 8)
        _count++;
}

void PhoneBook::searchContact()
{
    if (_count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    int i = 0;
    while (i < _count)
    {
        _contacts[i].showInfo(i);
        ++i;
    }
    std::cout << "Enter index to view details: ";
    int index;
    if (!(std::cin >> index))
    {
        std::cout << "Invalid input." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (index >= 0 && index < _count)
        _contacts[index].showDetails();
    else
        std::cout << "Index out of range." << std::endl;
}
