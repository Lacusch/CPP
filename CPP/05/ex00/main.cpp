#include "Bureacrat.hpp"
#include <exception>
#include <iostream>

static void to_High_Increment() {
  Bureaucrat b(120, "Thin_Lazy_lady");
  try {
    while (1) {
      std::cout << b << std::endl;
      b.incrementGrade();
    }
  } catch (const std::exception &e) {
    std::cerr << b << std::endl << e.what() << std::endl;
    std::cout << "to_High_Increment test" << std::endl;
  }
}

static void to_Low_Decrement() {
  Bureaucrat b(32, "Fat_Lazy_lady");
  try {
    while (1) {
      std::cout << b << std::endl;
      b.decrementGrade();
    }
  } catch (const std::exception &e) {
    std::cerr << b << std::endl << e.what() << std::endl;
    std::cout << "to_Low_Decrement test" << std::endl;
  }
}

static void to_Low_init() {
  try {
    std::cout << "Try to init Bureaucrat with grade 160 (to low)" << std::endl;
    Bureaucrat b(160, "Chunky");
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    std::cout << "to_Low_init test" << std::endl;
  }
}

static void to_High_init() {
  try {
    std::cout << "Try to init Bureaucrat with grade 0 (to high)" << std::endl;
    Bureaucrat b(0, "Thin");
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    std::cout << "to_High_init test" << std::endl;
  }
}

static void valid_Bureaucrat() {
  try {
    Bureaucrat b(1, "Pipedream");
    std::cout << "Testing " << b << std::endl;
    for (int i = 1; i < 150; i++) {
      std::cout << "Testing " << b << std::endl;
      b.decrementGrade();
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    std::cout << "valid_Bureaucrat test" << std::endl;
  }
  std::cout << "Finished without exception 🎉" << std::endl;
}
int main(int ac, char **av) {
  if (ac == 1) {
    std::cerr << "Usage:" << std::endl
              << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. to_High_Increment" << std::endl
              << "2. to_Low_Increment" << std::endl
              << "3. to_Low_init" << std::endl
              << "4. to_High_init" << std::endl
              << "5. Valid Bureaucrat" << std::endl
              << "6. Run all tests🧪" << std::endl;
    return 1;
  }
  if (ac > 2) {
    std::cerr << "Too many arguments" << std::endl
              << "Usage:" << std::endl
              << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. to_High_Increment" << std::endl
              << "2. to_Low_Increment" << std::endl
              << "3. to_Low_init" << std::endl
              << "4. to_High_init" << std::endl
              << "5. Valid Bureaucrat" << std::endl
              << "6. Run all tests🧪" << std::endl;
    return 1;
  }
  int arg = atoi(av[1]);
  if (arg < 1 || arg > 6) {
    std::cerr << "Invalid number" << std::endl
              << "Usage:" << std::endl
              << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. to_High_Increment" << std::endl
              << "2. to_Low_Increment" << std::endl
              << "3. to_Low_init" << std::endl
              << "4. to_High_init" << std::endl
              << "5. Valid Bureaucrat" << std::endl
              << "6. Run all tests🧪" << std::endl;
    return 1;
  }
  switch (arg) {
  case (1):
    to_High_Increment();
    break;
  case (2):
    to_Low_Decrement();
    break;
  case (3):
    to_Low_init();
    break;
  case (4):
    to_High_init();
    break;
  case (5):
    valid_Bureaucrat();
    break;
  default:
    to_High_Increment();
    to_Low_Decrement();
    to_Low_init();
    to_High_init();
    valid_Bureaucrat();
  }
}
