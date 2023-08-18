#ifndef ARRAY_TPP
#define ARRAY_TPP
#include <sys/_types/_size_t.h>

#include <cstddef>
#include <exception>

#include "stdlib.h"
// set the default type to int
#include "iostream"
template <typename T = int>

class Array {
 public:
  Array() : _Array(NULL), _size(0) {}

  Array(int n) : _size(n) {
    if (n < 0) throw IndexOutOfBoundsException();
    if (_size == 0)
      _Array = NULL;
    else
      _Array = new T[_size]();
  }

  Array(Array& cpy) : _size(cpy._size) {
    if (_size == 0) {
      _Array = NULL;
      cpy._size = 0;
    } else {
      _Array = new T[_size]();
      for (size_t i = 0; i < _size; ++i) _Array[i] = cpy._Array[i];
      _size = cpy._size;
    }
  }

  Array& operator=(Array const& rhs) {
    if (this != &rhs) {
      delete[] _Array;
      _size = rhs.arraySize;
      if (_size > 0) {
        _Array = new T[_size]();
        for (size_t i = 0; i < _size; ++i) _Array[i] = rhs._Array[i];
      }
    }
    return *this;
  }
  ~Array() { delete[] _Array; }

  T& operator[](size_t index) {
    if (index < 0 || index >= _size) throw Array::IndexOutOfBoundsException();
    return _Array[index];
  }

  T const& operator[](size_t index) const {
    if (index < 0 || index >= _size) throw Array::IndexOutOfBoundsException();
  }

  class IndexOutOfBoundsException : public std::exception {
   public:
    char const* what() const throw() { return "The index is out of bounds\n"; }
  };
  size_t size() const { return _size; }

 private:
  T* _Array;
  size_t _size;
};

#endif
