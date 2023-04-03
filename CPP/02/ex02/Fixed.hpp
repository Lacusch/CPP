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
  // ex02
  // Comparisons
  bool operator>(const Fixed &fixed) const;
  bool operator<(const Fixed &fixed) const;
  bool operator>=(const Fixed &fixed) const;
  bool operator<=(const Fixed &fixed) const;
  bool operator==(const Fixed &fixed) const;
  bool operator!=(const Fixed &fixed) const;
  // Arithmetic operators
  Fixed operator+(const Fixed &fixed) const;
  Fixed operator-(const Fixed &fixed) const;
  Fixed operator*(const Fixed &fixed) const;
  Fixed operator/(const Fixed &fixed) const;
  // Pre / post increment operators
  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);
  // Overloaded functions
  static Fixed &min(Fixed &c1, Fixed &c2);
  static const Fixed &min(Fixed const &c1, Fixed const &c2);
  static Fixed &max(Fixed &c1, Fixed &c2);
  static const Fixed &max(Fixed const &c1, const Fixed &c2);

private:
  int _fixed;
  static const int _fractional = 8;
};
std::ostream &operator<<(std::ostream &out, const Fixed f); // ex01

#endif
