#include <cstddef>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "identify.hpp"

int main() {
  Identity identity;
  Base *ptr = identity.generate();
  Base *to_ref = identity.generate();
  Base &ref = *to_ref;
  Base badCastTest;
  Base *iAmNull = NULL;

  identity.identify(ptr);
  identity.identify(ref);

  identity.identify(iAmNull);
  identity.identify(badCastTest);
  delete ptr;
  delete to_ref;
  return 0;
}
