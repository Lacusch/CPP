#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <stdexcept>
#include <sys/_types/_size_t.h>
#include <vector>
class Span {
public:
  // Orthodox canonical Form
  Span(int n);
  ~Span();
  Span(Span const &cpy);
  Span &operator=(Span const &rhs);
  void addNumber(int nb);
  int shortestSpan();
  int longestSpan();
  int get_Size() const;
  int get_Max_Size() const;
  std::vector<int> numbers;
  template <typename InputIterator>
  void addRange(InputIterator begin, InputIterator end) {
    while (begin != end) {
      addNumber(*begin);
      ++begin;
    }
  }
  void print_numbers() const;

private:
  Span();
  int _size;
};
#endif
