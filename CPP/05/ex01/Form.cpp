#include "Form.hpp"
#include "Bureacrat.hpp"
#include <string>

Form::Form(std::string const &name, bool is_signed, const int sign_grade,
           const int exec_grade)
    : name(name), is_signed(false), sign_grade(43), execute_grade(47) {}
Form::Form()
    : is_signed(false), sign_grade(43), execute_grade(47),
      name("Annoying chud") {}
Form::~Form() {}

Form::Form(const Form &a)
    : name(a.getName()), is_signed(false), sign_grade(a.get_Sign_Grade()),
      execute_grade(a.get_Execute_Grade()) {
  *this = a;
}

Form &Form::operator=(Form const &rhs) {
  is_signed = rhs.is_signed;
  return *this;
}

std::string const &Form::getName() const { return this->name; }

const int Form::get_Sign_Grade() const { return this->sign_grade; }

const int Form::get_Execute_Grade() const { return this->execute_grade; }
// Setters

// be Signed
//
// Exception classes

const char *Form::GradeTooLowException::what() const throw() {
  return "The Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
  return "The Grade is too high";
}