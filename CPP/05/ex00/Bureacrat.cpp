#include "Bureacrat.hpp"
#include <ostream>
#include <string>
// Orthodox Canonical Form

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(int grade, std::string const &name) : _name(name) {
  if (grade > min_grade) {
    Bureaucrat::GradeTooHighException();
  }
  if (grade < max_grade) {
    Bureaucrat::GradeTooLowException();
  }
  _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &a) { *this = a; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  _grade = rhs._grade;
  return *this;
}

// Exception classes

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "The Grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "The Grade is too high";
}

// Getters

std::string const &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

// setters

void Bureaucrat::incrementGrade() {
  if (_grade >= min_grade) {
    throw Bureaucrat::GradeTooHighException();
  }
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= max_grade) {
    throw Bureaucrat::GradeTooLowException();
  }
  _grade++;
}

// Insertion overload

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
  os << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
  return os;
}