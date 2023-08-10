#include "Intern.hpp"
#include "Bureacrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "iostream"
#include <cstddef>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &cpy) { (void)cpy; }

Intern &Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return *this;
}

AForm *makeForm(std::string const &name, std::string const &target) {
  int form_Id = 0;
  AForm *Form;
  std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm",
                          "PresidentialPardonForm"};

  while (form_Id < 3) {
    if (name == forms[form_Id]) {
      break;
    }
    form_Id++;
  }
  switch (form_Id) {
  case (0):
    Form = new ShrubberyCreationForm(target);
    break;
  case (1):
    Form = new RobotomyRequestForm(target);
  case (2):
    Form = new PresidentialPardonForm(target);
  default:
    std::cerr << "No form with that name found" << std::endl;
    Form = nullptr;
  }
  return Form;
}
