#include <iostream>
#include "Sample_Class.hpp"

Sample::Sample ( void )
{
	std::cout << "Constructor called" << std::endl;
	this->publicFOO = 0;
	std::cout << "this->publicFOO = " << this->publicFOO << std::endl;
	this->_prinvateFoo = 0;
	std::cout << "this->_privateFoo is " << this->_prinvateFoo << std::endl;
	this->publicBar();
	this->_private_Bar();
}

Sample::~Sample( void )
{
	std::cout << "Destructor called" << std::endl;
}

void Sample::publicBar() const {
	std::cout << "Member funciton publicBar called" << std::endl;
}

void Sample::_private_Bar (void ) const{
	std::cout << "Member function _privateBar called" << std::endl;
}

int main() {
	Sample instance;

	instance.publicFOO = 42;
	std::cout << "instance.public.FOO" << instance.publicFOO << std::endl;

	//instance._prinvateFoo = 42;
	//std::cout << "instance._prinvateFoo" << instance._prinvateFoo << std::endl;

	instance.publicBar();
	//instance._private_Bar();

	return 0;
}
