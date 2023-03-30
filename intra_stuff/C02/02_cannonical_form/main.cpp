#include "Sample.class.hpp"
#include <iostream>

int main() {
  Sample i1;
  Sample i2(42);
  Sample i3(i1);

  std::cout << i1 << std::endl;
  std::cout << i2 << std::endl;
  std::cout << i3 << std::endl;
  i3 = i2;
  std::cout << i3 << std::endl;
  return 0;
}
