#include "Scalar.hpp"
#include "iostream"
#include <cctype>
#include <exception>
#include <iomanip>

Scalar::Scalar(){};

Scalar::~Scalar(){};

Scalar::Scalar(Scalar &cpy) { *this = cpy; }

Scalar &Scalar::operator=(Scalar const &rhs) {
  if (this != &rhs)
    *this = rhs;
  return *this;
};

bool Scalar::handle_Literal(std::string const &input) {
  if (input.compare("+inf") == 0 || input.compare("+inff") == 0 ||
      input.compare("inff") == 0 || input.compare("inf") == 0) {
    std::cout << "char : impossible" << std::endl
              << "int : impossible" << std::endl
              << "float : inff" << std::endl
              << "double : inf " << std::endl;
    return 1;
  } else if (input.compare("-inf") == 0 || input.compare("-inff") == 0) {
    std::cout << "char : impossible" << std::endl
              << "int : impossible" << std::endl
              << "float : -inff" << std::endl
              << "double : -inf " << std::endl;
    return 1;
  }
  if (input.compare("naff") == 0 || input.compare("naf") == 0) {
    std::cout << "char : impossible" << std::endl
              << "int : impossible" << std::endl
              << "float : inff" << std::endl
              << "double : inf " << std::endl;
    return 1;
  }
  return false;
}

void Scalar::convert_Char(std::string input) {
  if (std::isprint(input[0])) {
    std::cout << "char : " << input << std::endl;
  } else if (input[0] < 0 || input[0] > 127) {
    std::cout << "char : impossible " << std::endl;
  } else {
    std::cout << "char : Non Displayable " << std::endl;
  }
  std::cout << "int : " << static_cast<int>(input[0]) << std::endl
            << std::fixed << std::setprecision(1)
            << "float : " << static_cast<float>(input[0]) << "f" << std::endl
            << "double : " << static_cast<double>(input[0]) << std::endl;
}

void Scalar::convert(std::string input) {

  int result = Scalar::parse_String(input);
  std::cout << result << std::endl;
  switch (result) {
  case CHAR:
    std::cout << "CHAR\n";
    break;
  case LITERAL:
    std::cout << "LITERAL\n";
    break;
  case NB:
    std::cout << "NB\n";
    break;
  default:
    std::cout << "Invalid input, please give a valid one and try again"
              << std::endl;
  }
}
