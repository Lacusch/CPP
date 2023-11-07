#include "RPN.hpp"
#include <stdexcept>

RPN::RPN(){};

RPN::RPN(std::string const &input_string) : input(input_string){};

RPN::~RPN() {}

RPN::RPN(RPN const &rhs) {
  this->input = rhs.input;
  this->int_stack = rhs.int_stack;
}

RPN &RPN::operator=(RPN const &rhs) {
  this->input = rhs.input;
  this->int_stack = rhs.int_stack;
  return *this;
}

void RPN::calculate() {
  std::string const char_list = VALID_ELEMENTS;
  std::string const number_list = NUMBERS;
  std::string const operator_list = OPERATORS;
  areValidChars();
  for (size_t i = 0; i < input.size(); i++) {
    if (std::isdigit(input[i]))
      int_stack.push(input[i] - '0');
    else if (operator_list.find(input[i]) != std::string::npos) {
      int_stack.push(doOperation(input[i]));
    }
  }
  std::cout << "The final result is: " << int_stack.top() << std::endl;
}

void RPN::areValidChars() const {
  size_t numbers = 0, operators = 0;
  std::string const char_list = VALID_ELEMENTS, number_list = NUMBERS,
                    operator_list = OPERATORS;
  for (size_t i = 0; input.size() > i; i++) {
    if (char_list.find(input[i]) == std::string::npos)
      throw std::logic_error("Error: invalid char in input");
    if (i > 0 && input[i] == ' ' && input[i - 1] == ' ')
      throw std::logic_error("Error: two spaces next to each other");
    if (i > 0 && input[i] != ' ' && input[i - 1] != ' ')
      throw std::logic_error("Error: two chars next to each other");
    if (number_list.find(input[i]) != std::string::npos)
      numbers++;
    if (std::string(OPERATORS).find(input[i]) != std::string::npos)
      operators++;
  }
  if (operators + 1 != numbers)
    throw std::logic_error("Error: not enough operators");
}

int RPN::doOperation(char c) {
  if (int_stack.size() < 2)
    throw std::logic_error("Error: invalid order in expression");
  int number2 = int_stack.top();
  int_stack.pop();
  int number1 = int_stack.top();
  int_stack.pop();
  int result = 42;
  if (number2 == 0)
    throw std::logic_error("Error: Division with 0 is not allowed");
  std::cout << "Sub result is: " << number1;
  if (c == '+') {
    result = number1 + number2;
    std::cout << " + ";
  } else if (c == '-') {
    result = number1 - number2;
    std::cout << " - ";
  } else if (c == '*') {
    result = number1 * number2;
    std::cout << " * ";
  } else if (c == '/') {
    result = number1 / number2;
    std::cout << " / ";
  }
  std::cout << number2 << " = " << result << std::endl;
  return result;
}
