#ifndef A_FORM_HPP
#define A_FORM_HPP
#include "Bureacrat.hpp"
#include "string"
class AForm {
public:
  // Orthodox Canonical AForm

  AForm(std::string const &name, const int sign_grade, const int exec_grade);
  virtual ~AForm();
  AForm(const AForm &cpy);
  AForm &operator=(const AForm &rhs);
  // static / calls variables
  
  const static int max_grade = 1;
  const static int min_grade = 150;
  // getters
  std::string const &getName() const;
  int get_Sign_Grade() const;
  int get_Execute_Grade() const;
  bool is_Signed() const;
  // setters
  void beSigned(Bureaucrat &signer);
  virtual void execute(Bureaucrat const &target) const = 0;
  // exceptions
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  std::string const name;
  bool is_signed;
  const int sign_grade;
  const int execute_grade;
};
std::ostream &operator<<(std::ostream &os, AForm const &AForm);

#endif
