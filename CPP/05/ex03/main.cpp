#include "AForm.hpp"
#include "Bureacrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

static void wrong_Intern_Test() {
  Intern i;
  AForm *test = nullptr;
  // (void)test;
  test = i.makeForm("tets", "test");
  // test = i.makeForm("asd", "ME");
  // test = i.makeForm("ShrubberyCreationForm", "ME");
}

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
              << "1. presidentialPardonForm_Test" << std::endl
              << "2. robotomyRequestForm_Test" << std::endl
              << "3. shrubberyCreationForm_Test" << std::endl
              << "4-n Run all tests🧪" << std::endl;
    return 1;
  }
  int arg = atoi(av[1]);
  (void)arg;
  switch (arg) {
  case (1):
    // presidentialPardonForm_Test();
    break;
  case (2):
    // robotomyRequestForm_Test();
    break;
  case (3):
    // shrubberyCreationForm_Test();
    break;
  default:
    // presidentialPardonForm_Test();
    // robotomyRequestForm_Test();
    // shrubberyCreationForm_Test();
    wrong_Intern_Test();
  }
  wrong_Intern_Test();
}
