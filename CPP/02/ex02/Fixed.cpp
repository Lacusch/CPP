#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &f) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  // std::cout << "Copy assignment operator called" << std::endl;

  if (this != &rhs)
    this->_fixed = rhs.getRawBits();
  return *this;
}

int Fixed::getRawBits() const {
  // std::cout << "getRawBits member function called" << std::endl;
  return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  _fixed = raw;
}

Fixed::Fixed(const int i) {
  _fixed = i << _fractional;
  // std::cout << "Overloaded(int) constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
  _fixed = roundf(f * (1 << _fractional));
  // std::cout << "Overloaded (float) constructor called" << std::endl;
}

int Fixed::toInt() const {
  int i = getRawBits() >> _fractional;
  return i;
}

float Fixed::toFloat() const {
  float f = (float)getRawBits() / (1 << _fractional);
  return f;
}

std::ostream &operator<<(std::ostream &out, const Fixed f) {
  out << f.toFloat();
  return out;
}

// ex02

bool Fixed::operator>(const Fixed &fixed) const {
  return this->_fixed > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
  return this->_fixed < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return this->_fixed >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return this->_fixed <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
  return this->_fixed == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return this->_fixed != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
  return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
  ++this->_fixed;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed nFix = *this;
  ++(this->_fixed);
  return nFix;
}

Fixed &Fixed::operator--(void) {
  --this->_fixed;
  return (*this);
}

Fixed &Fixed::min(Fixed &c1, Fixed &c2) {
  if (c1 <= c2)
    return c1;
  return c2;
}
Fixed Fixed::operator--(int) {
  Fixed nFix = *this;
  --(this)->_fixed;
  return nFix;
}
const Fixed &Fixed::min(Fixed const &c1, Fixed const &c2) {
  if (c1 <= c2)
    return c1;
  return c2;
}

Fixed &Fixed::max(Fixed &c1, Fixed &c2) {
  if (c1 >= c2)
    return c1;
  return c2;
}

const Fixed &Fixed::max(Fixed const &c1, Fixed const &c2) {
  if (c1 >= c2)
    return c1;
  return c2;
}
