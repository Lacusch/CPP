#include <cstddef>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "identify.hpp"
#include "iostream"

int main() {
  Identity identity;
  Base *ptr = identity.generate();
  Base *to_ref = identity.generate();
  Base &ref = *to_ref;
  Base badCastTest;
  Base *iAmNull = NULL;
  std::cout << "Valid tests:" << std::endl;
  identity.identify(ptr);
  identity.identify(ref);
  std::cout << "Invalid tests:" << std::endl;
  identity.identify(iAmNull);
  identity.identify(badCastTest);
  delete ptr;
  delete to_ref;
  return 0;
}
