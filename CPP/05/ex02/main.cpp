#include "AForm.hpp"
#include "Bureacrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

static void presidentialPardonForm_Test() {
  std::cout << "testing PresidentialPardonForm" << std::endl;
  Bureaucrat b1(1, "Rob");
  Bureaucrat b150(150, "Dave");
  std::cout << "Created two bureaucrats: " << std::endl << b1 << b150;
  PresidentialPardonForm f1("President");
  std::cout << "Created form :" << std::endl << f1;
  b150.executeForm(f1);
  b150.signForm(f1);
  b1.signForm(f1);
  b150.executeForm(f1);
  b1.executeForm(f1);
}

static void robotomyRequestForm_Test() {
  std::cout << "testing RobotomyRequestForm" << std::endl;
  Bureaucrat b1(1, "Rob");
  Bureaucrat b150(150, "Dave");
  std::cout << "Created two bureaucrats: " << std::endl << b1 << b150;
  RobotomyRequestForm f1("President");
  std::cout << "Created form :" << std::endl << f1;
  b150.executeForm(f1);
  b150.signForm(f1);
  b1.signForm(f1);
  b150.executeForm(f1);
  std::cout << "Success or failure can be seen down below :" << std::endl
            << std::endl;
  b1.executeForm(f1);
}
static void shrubberyCreationForm_Test() {
  std::cout << "testing ShrubberyCreationForm" << std::endl;
  Bureaucrat b1(1, "Rob");
  Bureaucrat b150(150, "Dave");
  std::cout << "Created two bureaucrats: " << std::endl << b1 << b150;
  ShrubberyCreationForm f1("President");
  std::cout << "Created form :" << std::endl << f1;
  b150.executeForm(f1);
  b150.signForm(f1);
  b1.signForm(f1);
  b150.executeForm(f1);
  std::cout << "Success or failure can be seen down below :" << std::endl
            << std::endl;
  b1.executeForm(f1);
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
  switch (arg) {
  case (1):
    presidentialPardonForm_Test();
    break;
  case (2):
    robotomyRequestForm_Test();
    break;
  case (3):
    shrubberyCreationForm_Test();
    break;
  default:
    presidentialPardonForm_Test();
    robotomyRequestForm_Test();
    shrubberyCreationForm_Test();
  }
}
