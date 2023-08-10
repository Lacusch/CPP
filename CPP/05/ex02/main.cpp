#include "AForm.hpp"
#include "Bureacrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av) {
  (void)ac;
  (void)av;
  PresidentialPardonForm f("Me");
  ShrubberyCreationForm f1("hello_tree");
  RobotomyRequestForm f2("Mr President");
  Bureaucrat b(1, "hello");
  try {
    b.signForm(f);
    f.execute(b);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b.signForm(f1);
    f.execute(b);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b.signForm(f2);
    b.executeForm(f2);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
