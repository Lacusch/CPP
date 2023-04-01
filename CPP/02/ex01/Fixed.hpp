#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed {
public:
  Fixed();
  ~Fixed();
  Fixed(Fixed const &f);
  Fixed &operator=(Fixed const &rhs);
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _fixed;
  static const int _fractional;
};
#endif
