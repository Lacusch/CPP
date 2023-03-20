#include "Contact.hpp"
#include <iomanip>

Contact::Contact () {}
Contact::~Contact() {}

void Contact::get_info() {
	std::cout << "Type all aplicable info of the contact one by one" << std::endl;
	std::cout << "WITHOUT SPACES !" << std::endl;
	std::cout << "First name is : " << std::endl;
	std::cin >> _F_Name;
	std::cout << "Last name is : " << std::endl;
	std::cin >> _L_Name;
	std::cout << "Nickname is : " << std::endl;
	std::cin >> _Nickname;
	std::cout << "Phone is : " << std::endl;
	std::cin >> _Phone;
	std::cout << "Deepest, darkest secret is : " << std::endl;
	std::cin >> _dark_secret;
	std::cout << std::endl;
}

std::string *Contact::get_element(int i){
	if (i == 0)
		return &this->_F_Name;
	if (i == 1)
		return &this->_L_Name;
	else
		return &this->_Nickname;
}

void Contact::print_elements() {
	std::cout << "First Name: " << this->_F_Name << std::endl;
	std::cout << "Last Name: " << this->_L_Name << std::endl;
	std::cout << "Nickname : " << this->_Nickname << std::endl;
	std::cout << "Phone : " << this->_Phone << std::endl;
	std::cout << "Deepset darkest secret: " << this->_dark_secret << std::endl;
}
