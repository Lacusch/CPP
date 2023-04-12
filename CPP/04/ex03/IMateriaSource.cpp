#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource() {
  std::cout << "IMateriaSource Default Constructor" << std::endl;
}

IMateriaSource::~IMateriaSource() {
  std::cout << "IMateriaSource Destructor" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &src) {
  std::cout << "IMateriaSource copy constructor called" << std::endl;
  *this = src;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &rhs) {
  (void)rhs;
  return *this;
}
