#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point {
public:
  Point();
  Point(const float x, const float y);
  Point(Point &cpy);
  Point &operator=(const Point &a);
  ~Point();
  // getters
  const Fixed &getX() const;
  const Fixed &getY() const;

private:
  const Fixed _x;
  const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif
