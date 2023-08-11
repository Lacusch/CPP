#include "Bureacrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

static void big_Form_sign() {
  std::cout << "Form with high sign grade(0)" << std::endl;
  try {
    Form test("name", 0, 60);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

static void small_Form_sign() {
  std::cout << "Form with low sign grade(160)" << std::endl;
  try {
    Form test("name", 160, 60);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

static void big_Form_exec() {
  std::cout << "Form with high exec grade(0)" << std::endl;
  try {
    Form test("name", 60, 0);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

static void small_Form_exec() {
  std::cout << "Form with low exec grade(160)" << std::endl;
  try {
    Form test("name", 60, 160);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

static void be_signed() {
  Bureaucrat b(43, "Intern");
  Bureaucrat b2(11, "Executive Intern");
  Form f("Transfer request", 11, 11);
  std::cout << b << b2 << f << std::endl;
  try {
    std::cout << "Bureaucrat with grade 43 trying ot sign a form with grade 11"
              << std::endl;
    b.signForm(f);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << "Bureaucrat with grade 11 trying ot sign a form with grade 11"
              << std::endl;
    b2.signForm(f);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
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
              << "1. big_Form_sign" << std::endl
              << "2. small_Form_sign" << std::endl
              << "3. big_Form_exec" << std::endl
              << "4. small_Form_exec" << std::endl
              << "5. be_signed" << std::endl
              << "6-n Run all tests🧪" << std::endl;
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
