#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>
class Sample{

public:
	Sample(void);
	~Sample(void);
};

Sample::Sample (void) {
	std::cout << "Constructor called" <<std::endl;
	return ;
}

Sample::~Sample (void){
	std::cout << "Destructor called" <<std::endl;
}

#endif