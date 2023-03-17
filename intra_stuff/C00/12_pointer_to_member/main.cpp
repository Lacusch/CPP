
#include "Sample_class.hpp"
#include "iostream"

Sample::Sample( void ) : foo( 0 ){
	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample( void) {
	std::cout << "Destructor called" << std::endl;
}

void Sample::bar() const {
	std::cout << "Member function bar called" << std::endl;
}

int main (void)
{
	Sample	instance;

	Sample	*instance_adress = &instance;

	int	Sample::*p = NULL;
	void	(Sample::*f)(void) const;

	p = &Sample::foo;

	std::cout << "Valua of members foo: " << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Valua of members foo: " << instance.foo << std::endl;
	instance_adress->*p = 42;
	std::cout << "Valua of members foo: " << instance.foo << std::endl;

	f = &Sample::bar;

	(instance.*f)();
	(instance_adress->*f)();
	return 0;
}