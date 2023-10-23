#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

int main(int ac, char **av) {
  try {
    if (ac != 2)
      throw std::logic_error("invalid number of args");
    BitcoinExchange Bitcoin(av[1]);
  } catch (std::exception &error) {
    std::cout << error.what() << std::endl;
  }
  return 0;
};
