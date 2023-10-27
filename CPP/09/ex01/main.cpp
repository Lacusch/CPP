#include "RPN.hpp"
#include <exception>
#include <stdexcept>

int main(int ac, char **av) {
  try {
    if (ac < 2)
      throw std::logic_error("Error: not enough args");
    std::string const input= av[1];
    RPN rpn(input);
    rpn.calculate();
  } catch (std::exception & e) {
  std::cout << e.what() << std::endl;
  }
  return 0;
}