#include "easyfind.tpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  numbers.push_back(-1);
  numbers.push_back(20);
  numbers.push_back(30);
  numbers.push_back(40);
  numbers.push_back(50);

  int value = 30;
  int index = easyfind(numbers, value);
  if (index != -1) {
    std::cout << "Value " << value << " found at index " << index << std::endl;
  } else {
    std::cout << "Value not found in container" << std::endl;
  }

  value = 60;
  index = easyfind(numbers, value);
  if (index != -1) {
    std::cout << "Value " << value << " found at index " << index << std::endl;
  } else {
    std::cout << "Value not found in container" << std::endl;
  }

  return 0;
}
