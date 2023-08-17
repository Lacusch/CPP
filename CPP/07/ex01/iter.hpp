#ifndef ITER_HPP
#define ITER_HPP
#include <sys/_types/_size_t.h>

#include "iostream"
template <typename T, typename F>
void iter(T array, size_t length, F* function) {
  for (size_t i = 0; i < length; i++) {
    function(array[i]);
  }
}

template <typename T>
void print(const T& element) {
  std::cout << "Value of element is: " << element << std::endl;
}

#endif