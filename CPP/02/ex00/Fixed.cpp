#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixed(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(Fixed const &f) {
  std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  std::cout << "Copy assignment operator called" << std::endl;

  if (this != &rhs)
    this->_fixed = rhs.getRawBits();
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _fixed = raw;
}
