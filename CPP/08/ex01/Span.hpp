#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <stdexcept>
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
  class no_Span : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  int get_Size();
  std::vector<int> numbers;

private:
  Span();
  int _size;
};
#endif
