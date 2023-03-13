#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

#include <iostream>
class Sample{

public:
	Sample(void);
	~Sample(void);

	void bar(void);
};

Sample::Sample (void) {
	std::cout << "Constructor called" <<std::endl;
	return ;
}

Sample::~Sample (void){
	std::cout << "Destructor called" <<std::endl;
}

void Sample::bar(void) {
	std::cout << "Member function called" << std::endl;
}
#endif