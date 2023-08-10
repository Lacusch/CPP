#include "Bureacrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(int ac, char **av) {
  (void)ac;
  (void)av;
  PresidentialPardonForm f("Me");
  ShrubberyCreationForm f1("hello_tree");
  Bureaucrat b(1, "hello");
  try {
    b.signForm(f);
  f.execute(b);
  } catch (std::exception & e) {
   std::cout << e.what() << std::endl;
  }
  try {
   b.signForm(f1);
   f.execute(b);
  } catch (std::exception &e) {
   std::cout << e.what() << std::endl;
  }
}
