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
  AForm *test = NULL;
  test = i.makeForm("tets", "test");
  test = i.makeForm("asd", "tree");
  test = i.makeForm("test3", "4");
}

static void intern_Shrubbery_Test() {
  std::cout << "Shrubbery Test" << std::endl;
  Intern i;
  AForm *form = NULL;
  Bureaucrat b(11, "Bob");
  std::cout << b;
  form = i.makeForm("ShrubberyCreationForm", "Directory");
  std::cout << "Form : " << *form << "was created by unnamed intern "
            << std::endl;
  b.signForm(*form);
  b.executeForm(*form);
  delete form;
}

static void intern_Pardon_Test() {
  std::cout << "Pardon Test" << std::endl;
  Intern i;
  AForm *form = NULL;
  Bureaucrat b(11, "Bob");
  std::cout << b;
  form = i.makeForm("PresidentialPardonForm", "Me");
  std::cout << "Form : " << *form << "was created by unnamed intern "
            << std::endl;
  b.signForm(*form);
  b.executeForm(*form);
  Bureaucrat b2(1, "BOB");
  std::cout << b2;
  b2.executeForm(*form);
  delete form;
}

static void intern_Robotomy_Test() {
  std::cout << "Robotomy Test" << std::endl;
  Intern i;
  AForm *form = NULL;
  Bureaucrat b(11, "Bob");
  std::cout << b;
  form = i.makeForm("RobotomyRequestForm", "Marvin");
  std::cout << "Form : " << *form << "was created by unnamed intern "
            << std::endl;
  b.signForm(*form);
  b.executeForm(*form);
  Bureaucrat b2(1, "BOB");
  std::cout << b2;
  b2.executeForm(*form);
  delete form;
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
              << "1. wrong_Intern_Test" << std::endl
              << "2. intern_Shrubbery_Test" << std::endl
              << "3. intern_Pardon_Test" << std::endl
              << "4. intern_Robotomy_Test" << std::endl
              << "5-n Run all tests🧪" << std::endl;
    return 1;
  }
  int arg = atoi(av[1]);
  (void)arg;
  switch (arg) {
  case (1):
    wrong_Intern_Test();
    break;
  case (2):
    intern_Shrubbery_Test();
    break;
  case (3):
    intern_Pardon_Test();
    break;
  case (4):
    intern_Robotomy_Test();
    break;
  default:
    wrong_Intern_Test();
    intern_Shrubbery_Test();
    intern_Pardon_Test();
    intern_Robotomy_Test();
  }
}
