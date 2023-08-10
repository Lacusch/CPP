#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureacrat.hpp"
#include "iostream"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

std::string const &ShrubberyCreationForm::get_Target() const { return _target; }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (is_Signed() == true) {
    std::cout << "Form is already signed" << std::endl;
    return;
  }
  if (executor.getGrade() > get_Execute_Grade()) {
    throw GradeTooLowException();
  }
  std::string tree;
  bool tf = (rand() % 2) != 0;
  std::ofstream tree_stream;
  // clang-format off
  if (tf == true) {
   tree =
        "          1111111\n"
		"         111111111\n"
		"        11       11\n"
		"        11  49    11\n"
		"         11 🤓-🤓 11\n"
		"          111111111\n"
		"            111\n"
		"            111\n"
		"            111\n"
		"____________111____________\n";
    // clang-format on
  } else {
   tree = "tree";
  }
}
