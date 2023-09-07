#include "Span.hpp"
#include "iostream"
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
  int minSpan = tmp[1] - tmp[0];
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
  return *std::max_element(numbers.begin(), numbers.end()) -
         *std::min_element(numbers.begin(), numbers.end());
}

int Span::get_Size() const { return numbers.size(); }

int Span::get_Max_Size() const { return _size; }

void Span::print_numbers() const {
  std::cout << "numbers are: ";
  for (std::vector<int>::const_iterator it = numbers.begin();
       it != numbers.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "end of numbers" << std::endl;
}
