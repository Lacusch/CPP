#include <iostream>
#include "Sample_class.hpp"

Sample::Sample (float const f) : pi ( f ), qd( 42) {
	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample (void)
{
	std::cout << "Destructor called" << std::endl;
}

void Sample::bar(void) const {
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;
}

int main ()
{
	Sample instance (3.13f);

	instance.bar();
	return (0);
}