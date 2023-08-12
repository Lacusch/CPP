#include "Scalar.hpp"
#include "iostream"

static bool invalid_String(std::string const &string) {
  (void)string;
  return false;
}

int main(int ac, char **av) {
  if (ac == 1 || ac > 2) {
    std::cerr << "Invalid number of arguments, please use " << std::endl;
    return 1;
  }
  if (invalid_String(av[1])){
    return 1;
  }
  Scalar converter;
  converter.convert(av[1]);
  return 0;
}