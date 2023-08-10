#include "RobotomyRequestForm.hpp"
#include "Bureacrat.hpp"
#include "iostream"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

std::string const &RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (is_Signed() == false) {
    throw FormIsNotSignedException();
  }
  if (executor.getGrade() > get_Execute_Grade()) {
    throw GradeTooLowException();
  }
  std::srand(time(NULL));
  if (std::rand() % 2 == 1) {
    std::cout << "The Robotomy of " << getTarget() << " has failed"
              << std::endl;
  } else {
    std::cout << getTarget() << " has been robotomized" << std::endl;
  }
}