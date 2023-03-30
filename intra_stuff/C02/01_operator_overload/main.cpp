#include "Integer.class.hpp"
#include <iostream>

int main() {
  Integer x(30);
  Integer y(20);
  Integer z(0);
  std::cout << "Value of x : " << x << std::endl;
  std::cout << "Value of y : " << y << std::endl;
  y = Integer(12);
  std::cout << "Value of y : " << y << std::endl;
  std::cout << "Value of z : " << y << std::endl;
  z = x + y;
  std::cout << "Value of z : " << y << std::endl;
  return 0;
}
