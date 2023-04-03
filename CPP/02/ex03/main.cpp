#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
int main() {
  Point a(-3, 4);
  Point b(4, 3);
  Point c(-2.4f, -2);
  Point p(2, 2);
  Point p2(-51, -51);
  bool inside;
  inside = bsp(a, b, c, p);
  std::cout << "testing with Triangle" << std::endl;
  std::cout << "A x: " << a.getX() << ", y: " << a.getY() << std::endl;
  std::cout << "B x: " << b.getX() << ", y: " << b.getY() << std::endl;
  std::cout << "C x: " << c.getX() << ", y: " << c.getY() << std::endl;
  std::cout << "P2 : x: " << p.getX() << ", y: " << p.getY() << std::endl;
  if (inside == true)
    std::cout << "inside!" << std::endl;
  else
    std::cout << "outside!" << std::endl;
  std::cout << std::endl << std::endl;
  inside = bsp(a, b, c, p2);
  std::cout << "testing with Triangle" << std::endl;
  std::cout << "A x: " << a.getX() << ", y: " << a.getY() << std::endl;
  std::cout << "B x: " << b.getX() << ", y: " << b.getY() << std::endl;
  std::cout << "C x: " << c.getX() << ", y: " << c.getY() << std::endl;
  std::cout << "P1 : x: " << p2.getX() << ", y: " << p2.getY()
            << std::endl;
  if (inside == true)
    std::cout << "inside!" << std::endl;
  else
    std::cout << "outside!" << std::endl;
  return 0;
}