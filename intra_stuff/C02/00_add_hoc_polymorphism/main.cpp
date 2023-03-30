#include "Sample.Class.hpp"

int main(void) {
  Sample test;
  int i = 1;
  float i2 = 2.312313;
  char i3 = '|';
  test.bar(i);
  test.bar(i2);
  test.bar(i3);
  test.bar(test);
  return 0;
}