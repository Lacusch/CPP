#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>
#include <ostream>

class Fixed {
public:
  Fixed();
  ~Fixed();
  Fixed(Fixed const &f);
  Fixed &operator=(Fixed const &rhs);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  // ex01
  Fixed(const int i);
  Fixed(const float f);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _fixed;
  static const int _fractional = 8;
};
std::ostream &operator<<(std::ostream &out, const Fixed f); // ex01
#endif
