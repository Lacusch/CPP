#include "sample_class.hpp"
#include "sample_class2.hpp"

#include <iostream>

int main () {
	std::cout << "initalisation of sample class1" << std::endl;
	Sample1 test ('a', 1, 1);
	std::cout << "initalisation of sample class2" << std::endl;
	Sample2 test2 ('a', 1, 1);
}