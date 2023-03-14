
#include <iostream>
#include "Sample_class.hpp"

Sample::Sample ( int v) : _foo( v) {
	std::cout << "Constructor " << std::endl;
}

Sample::~Sample( void ) {
	std::cout << "Destructor" << std::endl;
}

int Sample::get_Foo() const {
	return this->_foo;
}

int Sample::compare(Sample * other) const {
	if (this->_foo < other->get_Foo() )
		return -1;
	else if (this->_foo > other->get_Foo() )
		return 1;
	return 0;
}

int main () {

	Sample i1( 42 );
	Sample i2 ( 42);

	if (&i1 == &i2)
		std::cout << "The adress of i1 and i2 are equal" << std::endl;
	else
		std::cout << "The adress of i1 and i2 are NOT" << std::endl;
	if (i1.compare(&i2) == 0)
		std::cout << "The values of i1 and i2 are equal" << std::endl;
	else
		std::cout << "The values of i1 and i2 are NOT" << std::endl;
	return 0;
}