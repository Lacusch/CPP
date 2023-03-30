#include "Sample.Class.hpp"
#include <iostream>

Sample::Sample() { std::cout << "Constructor" << std::endl; }
Sample::~Sample() { std::cout << "Destructor" << std::endl; }
void Sample::bar(char const c) const {
  std::cout << "Member fc with char overload : " << c << std::endl;
}
void Sample::bar(int const n) const {
  std::cout << "Member fc with int overload : " << n << std::endl;
}
void Sample::bar(float const z) const {
  std::cout << "Member fc with float overload : " << z << std::endl;
}
void Sample::bar(Sample const & i) const {
  (void)i;
  std::cout << "Member fc with Sample.Class overload : " << &i << std::endl;
}
