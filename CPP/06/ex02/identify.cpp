#include "identify.hpp"

#include <exception>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "iostream"

Identity::Identity(){};

Identity::~Identity(){};

Identity::Identity(Identity const &cpy) { *this = cpy; };

Identity &Identity::operator=(Identity const &rhs) {
  if (this != &rhs) *this = rhs;
  return *this;
}

Base *Identity::generate(void) {
  std::srand(time(NULL));
  int generate = std::rand();
  if (generate % 3 == 0) {
    std::cout << "Creating A object" << std::endl;
    return new A;
  } else if (generate % 3 == 1) {
    std::cout << "Creating B object" << std::endl;
    return new B;
  } else if (generate % 3 == 2) {
    std::cout << "Creating C object" << std::endl;
    return new C;
  } else {
    return NULL;
  }
}

void Identity::identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL) {
    std::cout << "Is a pointer to class A" << std::endl;
    return;
  }
  if (dynamic_cast<B *>(p) != NULL) {
    std::cout << "Is a pointer to class B" << std::endl;
    return;
  }
  if (dynamic_cast<C *>(p) != NULL) {
    std::cout << "Is a pointer to class C" << std::endl;
    return;
  }
  std::cout << "Casting failed" << std::endl;
};

void Identity::identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "Is reference to class A" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "Is reference to class B" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "Is reference to class C" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  std::cout << "Bad reference, casting to A, B, C all threw exceptions"
            << std::endl;
}
