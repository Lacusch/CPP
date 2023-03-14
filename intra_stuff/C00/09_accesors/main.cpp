#include <iostream>
#include <system_error>
#include "Sample.Class.hpp"

Sample::Sample (void) {
	std::cout << "Constructor called " << std::endl;

	this->setFoo( 0 );
	std::cout << "this->get_Foo" << this->get_Foo() << std::endl;

}

Sample::~Sample( void ) {
	std::cout << "Destructor called " << std::endl;
}

int Sample::get_Foo() const {
	return this->_foo;
}

void Sample::setFoo(int v) {
	if (v >= 0)
	{
		this->_foo = v;
	}
	else {
		std::cerr << "Error, cannot set v to negative, use a positive inger and try again" << std::endl; 
	}
}

int main () {
	Sample instance;
	instance.setFoo(42);
	std::cout << "instance.getFoo() " << instance.get_Foo() << std::endl;
	instance.setFoo(-42);
	std::cout << "instance.getFoo() " << instance.get_Foo() << std::endl;

	return 0;
}