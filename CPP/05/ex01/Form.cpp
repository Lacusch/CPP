#include "Form.hpp"
#include "Bureacrat.hpp"
#include "iostream"
#include <ostream>
#include <string>

Form::Form(std::string const &name, const int sign_grade, const int exec_grade)
    : name(name), is_signed(false), sign_grade(43), execute_grade(47) {
  if (sign_grade < max_grade || exec_grade < max_grade) {
    throw Form::GradeTooHighException();
  }
  if (sign_grade > min_grade || exec_grade > min_grade) {
    throw Form::GradeTooLowException();
  }
}
Form::Form()
    : name("Annoying chud"), is_signed(false), sign_grade(43),
      execute_grade(47) {}
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

int Form::get_Sign_Grade() const { return this->sign_grade; }

int Form::get_Execute_Grade() const { return this->execute_grade; }

bool Form::is_Signed() const { return is_signed; }
// Setters

void Form::beSigned(Bureaucrat signer) {
  if (signer.getGrade() < get_Sign_Grade()) {
    throw Form::GradeTooHighException();
  }
  if (signer.getGrade() > get_Sign_Grade()) {
    throw Form::GradeTooLowException();
    if (is_Signed() == true) {
      std::cout << "Form " << name << "already signed" << std::endl;
    } else {
      std::cout << signer.getName() << " signed " << getName() << std::endl;
      is_signed = true;
    }
  }
}

// Exception classes

const char *Form::GradeTooLowException::what() const throw() {
  return "The Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
  return "The Grade is too high";
}

std::ostream &operator<<(std::ostream &os, Form const &form) {
  os << form.getName() << "has a required grade of " << form.get_Sign_Grade()
     << "and is ";
  if (form.is_Signed()) {
    os << "is signed" << std::endl;
  } else {
    os << "is NOT signed" << std::endl;
  }
  return os;
}
