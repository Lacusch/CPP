#include "Span.hpp"
#include <iterator>
#include <stdexcept>

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

#include "iostream"
void Span::addNumber(int nb) {
  if (get_Size() == get_Max_Size())
    throw std::overflow_error("Span is already full");
  numbers.push_back(nb);
}

int Span::shortestSpan() {
  if (numbers.size() <= 1) {
    throw std::logic_error("Not enough numbers to calculate shortest span");
  }
  std::vector<int> tmp = numbers;
  std::sort(tmp.begin(), tmp.end());
  int minSpan = numbers[1] - tmp[0];
  for (size_t i = 2; i < tmp.size(); ++i) {
    int span = tmp[i] - tmp[i - 1];
    if (span < minSpan) {
      minSpan = span;
    }
  }
  return minSpan;
}

int Span::longestSpan() {
  if (numbers.size() <= 1) {
    throw std::logic_error("Not enough numbers to calculate longest span");
  }
  std::cout << "The longest span is: ";
  return *std::max_element(numbers.begin(), numbers.end()) -
         *std::min_element(numbers.begin(), numbers.end());
}

int Span::get_Size() const { return numbers.size(); }

int Span::get_Max_Size() const { return _size; }
