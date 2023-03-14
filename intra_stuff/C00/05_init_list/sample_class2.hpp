#ifndef SAMPLE_CLASS2_HPP
#define SAMPLE_CLASS2_HPP
#include <iostream>
class Sample2 {

public:
	char     a1;
    int      a2;
    float    a3;

    Sample2( char p1, int p2, float p3);
    ~Sample2 ( void );
};

Sample2::Sample2 (char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) {
	std::cout << "Sample2 Constructor called" << std::endl;
	std::cout << "this->p1 = " << this->a1 << std::endl;
	std::cout << "this->p2 = " << this->a2 << std::endl;
	std::cout << "this->p3 = " << this->a3 << std::endl;
}

Sample2::~Sample2 (void) {
	std::cout << "Sample 2 Destructor called" << std::endl;
}
#endif