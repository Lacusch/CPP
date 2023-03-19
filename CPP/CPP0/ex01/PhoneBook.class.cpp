#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/_types/_size_t.h>
#include "PhoneBook.class.hpp"

Phone_Book::Phone_Book () {
	this->_oldest = 0;
	this->_number = 0;
}

Phone_Book::~Phone_Book (){}

void Phone_Book::run_phoneBook( void ) {
	std::cout << std::endl;
	std::cout << "Options :" << std::endl;
	std::cout << "ADD: Add a new user to the database" << std::endl;
	std::cout << "SEARCH: Search trough the database" << std::endl;
	std::cout << "EXIT: Exit the database" << std::endl;	
}

void Phone_Book::add_contact() {
	if (_number == 8)
	{
		std::cout << "Too many contacts replacing oldest one " << (_oldest + 1) << std::endl;
		this->_cottacts[_oldest].get_info();
		if (_oldest == 8)
			_oldest = 0;
		else
		 	_oldest++;
		return;
	}
	this->_cottacts[_number].get_info();
	this->_number++;
	std::cout << "index is" << this->_number;
}

void Phone_Book::list_contact() {

	if (this->_number == 0)
	{
		std::cout << "Empty phonebook, add an entry and try again" << std::endl;
		return;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|   index  |first name|last name | nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i != _number; i++) {
		this->list_elem(this->_cottacts[i], i + 1);
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void Phone_Book::list_elem(Contact i, int index) {
	std::string print;

	std::cout << "|         " << index << "|";
	for (int i2 = 0; i2< 3; i2++) {
		if (i.get_element(i2)->size() < 10) {
		print = *i.get_element(i2);
		std::cout << std::right << std::setw(10) << print;
		std::cout << "|";
		}
		else {
			print = i.get_element(i2)->substr(0, 9).append(".");
			std::cout << print;
			std::cout << "|";
		}
	}
	std::cout << std::endl;
}