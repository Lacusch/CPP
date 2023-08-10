#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureacrat.hpp"
#include "iostream"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

std::string const &ShrubberyCreationForm::get_Target() const { return _target; }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (is_Signed() == false) {
    throw FormIsNotSignedException();
  }
  if (executor.getGrade() > get_Execute_Grade()) {
    throw GradeTooLowException();
  }
  std::string tree;
  tree = "          1111111\n"
         "         111111111\n"
         "        11       11\n"
         "        11      11\n"
         "         11 🤓-🤓 11\n"
         "          111111111\n"
         "            111\n"
         "            111\n"
         "            111\n"
         "____________111____________\n";
  std::ofstream tree_stream(get_Target() + "_shrubbery");
  if (!tree_stream) {
    throw std::runtime_error("Can't open file stream");
  }
  tree_stream << tree;
  std::cout << "Three created " << std::endl;
}
