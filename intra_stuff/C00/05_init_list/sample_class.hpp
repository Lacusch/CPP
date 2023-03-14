#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP

#include <iostream>

class Sample1 {

public:

    char     a1;
    int      a2;
    float    a3;

    Sample1( char p1, int p2, float p3);
    ~Sample1 ( void );
};

Sample1::Sample1( char p1, int p2, float p3) {
	std::cout << "Sample Constructor called" << std::endl;

	this->a1 = p1;
	std::cout << "this->a1 = " << this->a1 << std::endl;

	this->a2 = p2;
	std::cout << "this->a1 = " << this->a2 << std::endl;

	this->a3 = p3;
	std::cout << "this->a1 = " << this->a3 << std::endl;
}

Sample1::~Sample1( void ) {

	std::cout << "Sample Destructor called" << std::endl;
}

#endif