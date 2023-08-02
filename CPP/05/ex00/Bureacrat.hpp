#include "string"
#include <exception>

class Bureaucrat {
  std::string const name;
  int grade;
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
};
