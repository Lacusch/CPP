#include "Bureacrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include "PresidentialPardonForm.hpp"

int main(int ac, char **av) {
  (void)ac;
  (void)av;
  PresidentialPardonForm f("Me");
  Bureaucrat b(50, "hello");
  try {
  f.execute(b);
  } catch (std::exception & e) {
   std::cout << e.what() << std::endl; 
  }
}
