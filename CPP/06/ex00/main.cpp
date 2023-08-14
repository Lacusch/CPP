#include "Scalar.hpp"
#include "iostream"

int main(int ac, char **av) {
  if (ac == 1 || ac > 2) {
    std::cerr << "Invalid number of arguments" << std::endl;
    return 1;
  }
  Scalar converter;
  converter.convert(av[1]);
  return 0;
}