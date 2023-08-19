#include "Span.hpp"
#include <iterator>

Span::Span(int n) : _size(n){};

Span::~Span(){};

Span::Span(Span const &cpy) : _size(cpy._size) { numbers = cpy.numbers; }

Span &Span::operator=(Span const &rhs) {
  if (this != &rhs) {
    this->_size = rhs._size;
    this->numbers = rhs.numbers;
  }
  return *this;
}

void Span::addNumber(int nb) {
  if (get_Size() == numbers.size())
    throw(no_Span());
  numbers.push_back(nb);
}

