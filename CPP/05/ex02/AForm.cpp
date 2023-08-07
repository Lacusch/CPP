#include "AForm.hpp"
#include "Bureacrat.hpp"
#include "iostream"
#include <ostream>
#include <string>

AForm::AForm(std::string const &name, const int sign_grade, const int exec_grade)
    : name(name), is_signed(false), sign_grade(sign_grade),
      execute_grade(exec_grade) {
  if (sign_grade < max_grade || exec_grade < max_grade) {
    throw AForm::GradeTooHighException();
  }
  if (sign_grade > min_grade || exec_grade > min_grade) {
    throw AForm::GradeTooLowException();
  }
}

AForm::~AForm() {}

AForm::AForm(const AForm &a)
    : name(a.getName()), is_signed(false), sign_grade(a.get_Sign_Grade()),
      execute_grade(a.get_Execute_Grade()) {
  *this = a;
}

AForm &AForm::operator=(AForm const &rhs) {
  is_signed = rhs.is_signed;
  return *this;
}

std::string const &AForm::getName() const { return this->name; }

int AForm::get_Sign_Grade() const { return this->sign_grade; }

int AForm::get_Execute_Grade() const { return this->execute_grade; }

bool AForm::is_Signed() const { return is_signed; }
// Setters

void AForm::beSigned(Bureaucrat &signer) {
  if (signer.getGrade() <= this->get_Sign_Grade()) {
    if (is_Signed() == true) {
      std::cout << "AForm " << name << "already signed" << std::endl;
    } else {
      std::cout << signer.getName() << " signed " << getName() << std::endl;
      is_signed = true;
    }
  } else {
    throw AForm::GradeTooLowException();
  }
}

// Exception classes

const char *AForm::GradeTooLowException::what() const throw() {
  return "The Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "The Grade is too high";
}

std::ostream &operator<<(std::ostream &os, AForm const &Aform) {
  os << Aform.getName() << " Aform has a required grade of " << Aform.get_Sign_Grade()
     << " and is ";
  if (Aform.is_Signed()) {
    os << "is signed" << std::endl;
  } else {
    os << "is NOT signed" << std::endl;
  }
  return os;
}
