#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>
#include <type_traits>

int	main(void ) {
	Phone_Book phonebook;
	
	std::string line;

	std::cout << "My Awesome Phonebook ☎️" << std::endl;
	phonebook.run_phoneBook();
	while (1) {
		std::getline(std::cin, line);
		if (line == "ADD")
			phonebook.add_contact();
		else if (line == "SEARCH")
			phonebook.list_contact();
		else if (line == "EXIT")
			break;
		else
			phonebook.run_phoneBook();
	}
	std::cout << "Exiting this Awesome Phonebook 😊" << std::endl;
	return 0;
}
