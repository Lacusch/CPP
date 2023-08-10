#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureacrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

std::string const &PresidentialPardonForm::get_Target() const {
  return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (is_Signed() == false) {
    throw FormIsNotSignedException();
  }
  if (executor.getGrade() > get_Execute_Grade()) {
    throw GradeTooLowException();
  }
  std::cout << get_Target() << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
