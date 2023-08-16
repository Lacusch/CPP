#include <sys/_types/_size_t.h>

#include <cstddef>
#include <string>

#include "Scalar.hpp"

bool Scalar::only_Space(std::string const &string) {
  for (size_t i = 0; i < string.size(); i++) {
    if (string[i] != ' ') return 0;
  }
  return 1;
};

std::string Scalar::trim_Space(std::string &to_Trim) {
  // I could use std::string::size_type here as well (as that sis defined as
  // size_t)
  size_t start;
  size_t finish;
  start = to_Trim.find_first_not_of(" ");
  finish = to_Trim.find_first_not_of(" ");
  std::string trimmed = to_Trim.substr(start, finish - start + 1);
  return trimmed;
};

bool Scalar::invalid_Space(std::string const &string) {
  if (string.find(" ") != std::string::npos) {
    return true;
  }
  return false;
};

bool Scalar::is_Lit(std::string const &string) {
  std::string literals[8] = {"inf",  "inff",  "-inf", "-inff",
                             "+inf", "+inff", "nan",  "nanf"};
  for (int i = 0; i < 8; i++) {
    if (literals[i].compare(string) == 0) {
      return true;
    }
  }
  return false;
};

bool Scalar::is_Nb(std::string &string) {
  bool dot;
  // removing potential f
  if (string[string.size() - 1] == 'f') string.erase(string.size() - 1);
  for (size_t i = 0; i < string.size(); i++) {
    if (string[i] == '.') {
      if (!dot)
        dot = true;
      else
        return false;
    }
    if ((string[i] > '9' || string[i] < '0') && string[i] != '.') return false;
  }
  return true;
};
#include "iostream"
bool Scalar::is_Char(std::string const &string) {
  if (string.size() > 1) return false;
  if (std::isprint(string[0])) {
    return true;
  }
  return false;
};

int Scalar::parse_String(std::string &input) {
  std::string trimmed;
  if (Scalar::only_Space(input)) return EMPTY;
  trimmed = Scalar::trim_Space(input);
  if (Scalar::invalid_Space(input)) return INVALID;
  if (Scalar::is_Lit(input)) return LITERAL;
  if (Scalar::is_Nb(input)) return NB;
  if (Scalar::is_Char(input)) return CHAR;
  return INVALID;
};
