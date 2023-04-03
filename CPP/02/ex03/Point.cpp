#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() {
  // std::cout << "Normal constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
  // std::cout << "Float constructor called" << std::endl;
}

Point::Point(Point &cpy) : _x(cpy.getX()), _y(cpy.getY()) {
  // std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &a) {
  // std::cout << "Copy assignment operator called" << std::endl;
  // to fix
  (void)a;
  return *this;
}

Point::~Point() {
  // std::cout << "Destructor called" << std::endl;
}

const Fixed &Point::getX() const { return _x; }

const Fixed &Point::getY() const { return _y; }
