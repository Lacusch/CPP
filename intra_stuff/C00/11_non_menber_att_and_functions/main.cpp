#include "iostream"
#include "Sample_class.hpp"

Sample::Sample( void ) {
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst += 1;
}

Sample::~Sample( void)
{
	std::cout << "Destructor called" << std::endl;
	Sample::_nbInst -= 1;
}

int	Sample::get_Nb_inst( void )
{
	return Sample::_nbInst;
}

int Sample::_nbInst = 0;

void	f0( void )
{
	Sample instance;

	std::cout << "Number of instaces : " << Sample::get_Nb_inst() << std::endl;
}

void	f1( void )
{
	Sample instance;

	std::cout << "Number of instaces : " << Sample::get_Nb_inst() << std::endl;
	f0();
}

int main() {
	std::cout << "Number of instaces : " << Sample::get_Nb_inst() << std::endl;
	f1();
	std::cout << "Number of instaces : " << Sample::get_Nb_inst() << std::endl;
}