#include "string"
#include <exception>

class Bureaucrat {
  std::string const name;
  int grade;
  class grade_to_low : std::exception {
    const char *what() const throw() { return "exception"; }
  };
};
