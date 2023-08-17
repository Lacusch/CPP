#include "iter.hpp"

int main() {
  int int_Array[] = {1, 2, 3, 4, 5, 6, 7};
  size_t int_Array_Length = sizeof(int_Array) / sizeof(int);
  char charArray[] = {'<', '>', '\\', '/', '#'};
  size_t charArrayLength = sizeof(charArray) / sizeof(char);
  std::string stringArray[] = {"apple", "banana", "citrus", "donkey",
                               "elephant"};
  size_t stringArrayLength = 4;
  std::cout << "Testing int Array" << std::endl;
  iter(int_Array, int_Array_Length, print<int>);
  std::cout << "Testing char Array" << std::endl;
  iter(charArray, charArrayLength, print<char>);
  std::cout << "Testing string Array" << std::endl;
  iter(stringArray, stringArrayLength, print<std::string>);
  return 0;
}