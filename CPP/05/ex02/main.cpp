#include "AForm.hpp"
#include "Bureacrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av) {
  if (ac == 1 || ac > 2) {
    if (ac > 2) {
      std::cerr << "Too many arguments" << std::endl;
    } else {
      std::cerr << "Usage:" << std::endl;
    }
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. big_Form_sign" << std::endl
              << "2. small_Form_sign" << std::endl
              << "3. big_Form_exec" << std::endl
              << "4. small_Form_exec" << std::endl
              << "5. be_signed" << std::endl
              << "6. Run all tests🧪" << std::endl;
    return 1;
  }
  int arg = atoi(av[1]);
  switch (arg) {
  case (1):
    big_Form_sign();
    break;
  case (2):
    small_Form_sign();
    break;
  case (3):
    big_Form_exec();
    break;
  case (4):
    small_Form_exec();
    break;
  case (5):
    be_signed();
    break;
  default:
    big_Form_sign();
    small_Form_sign();
    big_Form_exec();
    small_Form_exec();
    be_signed();
  }
}
