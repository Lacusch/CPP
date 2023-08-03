#include "Bureacrat.hpp"
#include <exception>
#include <iostream>

int main() {
  try {
    Bureaucrat t(100, "name");
    std::cout << t.getName() << std::endl;
    t.incrementGrade();
    std::cout << t.getName() << std::endl;
    t.incrementGrade();
    std::cout << t.getGrade() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what();
    return 1;
  }
}