#ifndef ARRAY_TPP
#define ARRAY_TPP
#include <exception>

#include "stdlib.h"
template <typename T>

class Array {
 public:
  Array() : _Array(NULL), _size(0) {}
  Array(unsigned int n) : _size(n) {
    if (n <= 0) {
      if (n < 0) n = 0;
      _Array = NULL;
    } else {
      _Array = new T[n]();
    }
  }
  Array(Array& cpy) {
    if (_size == 0) {
      _Array = NULL;
    } else {
      _Array = new T[_size]();
      for (size_t i = 0; i < _size; ++i) _Array[i] = cpy._Array[i];
    }
  }
  Array& operator=(Array const& rhs);
  ~Array() { delete[] _Array; }

  size_t size() const { return _size; }

 private:
  T* _Array;
  size_t _size;
};

#endif
