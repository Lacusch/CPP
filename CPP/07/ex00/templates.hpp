#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP
template <typename T>
T const max(T const &x, T const &y) {
  return (x > y ? x : y);
}

template <typename T>
T const min(T const &x, T const &y) {
  return (x > y ? x : y);
}

template <typename T>
void swap(T &x, T &y) {
  T tmp = x;
  x = y;
  y = tmp;
}
#endif