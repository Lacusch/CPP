#include "Span.hpp"
#include "iostream"
#include <exception>
#include <iterator>
#include <vector>

// shortest span
//TODO: Shortest span doesn't work
void static shortest_Span() {
  try {
    Span span = Span(5);
    span.addNumber(54);
    span.addNumber(6);
    span.addNumber(25);
    span.addNumber(8);
    span.addNumber(14);
    std::cout << "The span size is: " << span.get_Size() << std::endl;
    std::cout << span.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
// longest span

// Full

// Fill

// All
int main(int ac, char **av) {
  if (ac == 1 || ac > 2) {
    std::cerr << "Usage:" << std::endl;
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. float_Array_Test" << std::endl
              << "2. over_Index_Test" << std::endl
              << "3. negative_Index_Test" << std::endl
              << "4. valid_Arrays_Test" << std::endl
              << "5-n Run all tests🧪" << std::endl;
    return 1;
  }
  int arg = atoi(av[1]);
  if (arg < 1) {
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. float_Array_Test" << std::endl
              << "2. over_Index_Test" << std::endl
              << "3. negative_Index_Test" << std::endl
              << "4. valid_Arrays_Test" << std::endl
              << "5-n Run all tests🧪" << std::endl;
    return 1;
  }
  switch (arg) {
  case (1):
    shortest_Span();
    break;
  case (2):
    // over_Index_Test();
    break;
  case (3):
    // negative_Index_Test();
    break;
  case (4):
    // valid_Arrays_Test();
    break;
  default:
    shortest_Span();
    // over_Index_Test();
    // negative_Index_Test();
//     valid_Arrays_Test();
  }
  return 0;
}
