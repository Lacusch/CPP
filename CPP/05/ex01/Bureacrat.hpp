#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "string"
#include <exception>
class Form;

class Bureaucrat {
public:
  // static variables

  const static int max_grade = 1;
  const static int min_grade = 150;
  // Orthodox Canonical Form

  Bureaucrat(int grade, std::string const &name);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &a);
  Bureaucrat &operator=(const Bureaucrat &rhs);
  // Exception classes

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  // getters

  std::string const &getName() const;
  int getGrade() const;
  // setters

  void incrementGrade();
  void decrementGrade();

  // Form stuff

  void signForm(const Form &Form);

private:
  std::string const _name;
  int _grade;
  Bureaucrat();
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);
#endif
