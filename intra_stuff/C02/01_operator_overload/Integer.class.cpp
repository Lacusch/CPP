#include "Integer.class.hpp"
Integer::Integer(int const n) {
  std::cout << "Contractor with value " << n << std::endl;
  _n = n;
}
Integer::~Integer() {
  std::cout << "Destructor with value " << this->_n << std::endl;
}
int Integer::getValue() const { return this->_n; }
Integer &Integer::operator=(const Integer &rhs) {
  std::cout << "Assignation operator calls from " << this->_n;
  std::cout << " to " << rhs.getValue() << std::endl;
  this->_n = rhs.getValue();
  return *this;
}
Integer Integer::operator+(const Integer &rhs) const {
  std::cout << "Addition operator calls with this " << this->_n;
  std::cout << " and " << rhs.getValue() << std::endl;
  return Integer(this->_n + rhs.getValue());
}
std::ostream &operator<<(std::ostream &o, Integer const &rhs) {
  o << rhs.getValue();
  return o;
}
