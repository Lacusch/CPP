#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <sys/_types/_size_t.h>

#define VALID_ELEMENTS " 01234566789+-/*"
#define NUMBERS "0123456789"
#define OPERATORS "+-*/"

class RPN {
public:
  RPN(std::string const &input);
  ~RPN();
  RPN(RPN const &rhs);
  RPN &operator=(RPN const &rhs);
  void calculate();

private:
  RPN();
  std::stack<int> int_stack;
  std::string input;
  void areValidChars() const;
  int doOperation(char c);
};
#endif