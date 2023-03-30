#include "Sample.class.hpp"
#include <iostream>
#include <ostream>

Sample::Sample() : _foo(0) { std::cout << "Default Constructor" << std::endl; }
Sample::~Sample() { std::cout << "Destructor called" << std::endl; }
Sample::Sample(Sample const &src) {
  std::cout << "Copy constructor" << std::endl;
  *this = src;
}
Sample::Sample(int const n) : _foo(n) {
  std::cout << "Paramedic Constructor" << std::endl;
}
int Sample::getFoo() const { return this->_foo; }
Sample &Sample::operator=(const Sample &rhs) {
  std::cout << "Assignment operator called" << std::endl;

  if (this != &rhs)
    this->_foo = rhs.getFoo();
  return *this;
}

std::ostream &operator<<(std::ostream &o, Sample const &i) {
  o << "The value of _foo is : " << i.getFoo();
  return o;
}
