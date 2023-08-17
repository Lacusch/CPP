#include "Scalar.hpp"
#include "iostream"
#include <cctype>
#include <exception>
#include <iomanip>
#include <limits>
#include <sstream>

Scalar::Scalar(){};

Scalar::~Scalar(){};

Scalar::Scalar(Scalar &cpy) { *this = cpy; }

Scalar &Scalar::operator=(Scalar const &rhs) {
  if (this != &rhs)
    *this = rhs;
  return *this;
};

void Scalar::print_Literal(std::string const &input) {
  std::cout << "char: impossible" << std::endl
            << "int: impossible" << std::endl;
  if (input.compare("+inf") == 0 || input.compare("+inff") == 0 ||
      input.compare("inff") == 0 || input.compare("inf") == 0) {
    std::cout << std::numeric_limits<float>::infinity() << "f" << std::endl
              << std::numeric_limits<double>::infinity() << std::endl;
  } else if (input.compare("-inf") == 0 || input.compare("-inff") == 0) {
    std::cout << "-" << std::numeric_limits<float>::infinity() << "f"
              << std::endl
              << "-" << std::numeric_limits<double>::infinity() << std::endl;
  } else
    std::cout << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl
              << std::numeric_limits<double>::quiet_NaN() << std::endl;
}

void Scalar::convert_Char(std::string input) {
  if (std::isprint(input[0])) {
    std::cout << "char: " << input << std::endl;
  } else if (input[0] < 0 || input[0] > 127) {
    std::cout << "char: impossible " << std::endl;
  } else {
    std::cout << "char: Non Displayable " << std::endl;
  }
  std::cout << "int: " << static_cast<int>(input[0]) << std::endl
            << std::fixed << std::setprecision(1)
            << "float: " << static_cast<float>(input[0]) << "f" << std::endl
            << "double: " << static_cast<double>(input[0]) << std::endl;
}

void Scalar::convertInt(double &nb) {
  if (static_cast<double>(std::numeric_limits<float>::max()) < nb ||
      static_cast<double>(std::numeric_limits<float>::max()) < nb) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(nb) << std::endl;
  }
};

void Scalar::convertFloat(double &nb) {
  if (static_cast<double>(std::numeric_limits<float>::max()) < nb ||
      -static_cast<double>(std::numeric_limits<float>::max()) > nb)
    std::cout << "float: impossible" << std::endl;
  else
    std::cout << "float:" << std::fixed << std::setprecision(1)
              << static_cast<float>(nb) << "f" << std::endl;
}

void Scalar::convertDouble(double &nb) {
  if (std::numeric_limits<double>::max() < nb ||
      -std::numeric_limits<double>::max() > nb) {
    std::cout << "double: impossible " << std::endl;
  } else {
    std::cout << "double: " << std::fixed << std::setprecision(1) << nb
              << std::endl;
  }
}
void Scalar::convert_Number(std::string input) {
  double nb;
  std::istringstream iss(input);
  iss >> nb;
  if (nb > 32 && 127 > nb)
    std::cout << "char: " << static_cast<char>(nb) << std::endl;
  else
    std::cout << "char: "
              << "Non displayable " << std::endl;
  Scalar::convertInt(nb);
  Scalar::convertFloat(nb);
  Scalar::convertDouble(nb);
}

void Scalar::convert(std::string input) {
  int result = Scalar::parse_String(input);
  switch (result) {
  case CHAR:
    Scalar::convert_Char(input);
    break;
  case LITERAL:
    Scalar::print_Literal(input);
    break;
  case NB:
    Scalar::convert_Number(input);
    break;
  default:
    std::cout << "Invalid input, please give a valid one and try again"
              << std::endl;
  }
}
