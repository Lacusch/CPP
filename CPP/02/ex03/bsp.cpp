#include "Fixed.hpp"
#include "Point.hpp"
/*
Math is based on this article:
<https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle>
*/
static int orientation(const Point &a, const Point &b, const Point &c) {
  Point ab(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() -
           a.getY().toFloat());
  Point ac(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() -
           a.getY().toFloat());
  float cross_product;
  cross_product = (ab.getX().toFloat() * ac.getY().toFloat()) -
                  ab.getY().toFloat() * ab.getY().toFloat();
  if (cross_product < 0)
    return 1;
  return -1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  int turns;

  turns = orientation(a, b, point) + orientation(b, c, point) +
          orientation(c, a, point);
  if (turns == 3)
    return true;
  return false;
}
