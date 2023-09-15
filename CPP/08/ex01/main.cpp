#include "Span.hpp"
#include "iostream"
#include <exception>
#include <iterator>
#include <vector>

// shortest span
void static shortest_Span() {
  try {
    Span span(5);
    span.addNumber(54);
    span.addNumber(6);
    span.addNumber(25);
    span.addNumber(8);
    span.addNumber(14);
    span.print_numbers();
    std::cout << "The span size is: " << span.get_Size() << std::endl;
    std::cout << span.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
// longest span
void static longest_Span() {
  try {
    Span span(5);
    span.addNumber(123);
    span.addNumber(321);
    span.addNumber(11);
    span.addNumber(14);
    span.addNumber(-1);
    span.print_numbers();
    std::cout << "The span size is: " << span.get_Size() << std::endl;
    std::cout << span.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
// Full

void static vector_Full() {
  std::cout << "Adding element to a vector already full" << std::endl
            << "Should throw and exception" << std::endl;
  try {
    Span span(5);
    span.addNumber(1);
    span.addNumber(1);
    span.addNumber(1);
    span.addNumber(1);
    span.addNumber(1);
    span.addNumber(1);
    span.print_numbers();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

std::vector<int> static generateRandomNumbers(int numElements) {
  std::vector<int> randomNumbers;
  // Seed the random number generator with the current time
  std::srand(std::time(NULL));
  randomNumbers.reserve(numElements + 1);
  // Generate 'numElements' random integers and add them to the vector
  for (int i = 0; i < numElements; ++i) {
    int randomNumber = std::rand();
    randomNumbers.push_back(randomNumber);
  }
  return randomNumbers;
}

void static big_Vector() {
  int numbers;
  numbers = 10000;
  Span s(numbers);
  std::vector<int> v;
  v = generateRandomNumbers(numbers);
  s.addRange(v.begin(), v.end());
  std::cout << "size is: " << s.get_Size()
            << " max size is: " << s.get_Max_Size() << std::endl;
  std::cout << s.longestSpan() << std::endl;
  std::cout << s.shortestSpan() << std::endl;
  s.print_numbers();
}
// All
int main(int ac, char **av) {
  if (ac == 1 || ac > 2) {
    std::cerr << "Usage:" << std::endl;
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. shortest_Span" << std::endl
              << "2. longest_Span" << std::endl
              << "3. vector_Full" << std::endl
              << "4. big_Vector" << std::endl
              << "5-n Run all tests🧪" << std::endl;
    return 1;
  }
  int arg = atoi(av[1]);
  if (arg < 1) {
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. shortest_Span" << std::endl
              << "2. longest_Span" << std::endl
              << "3. vector_Full" << std::endl
              << "4. big_Vector" << std::endl
              << "5-n Run all tests🧪" << std::endl;
    return 1;
  }
  switch (arg) {
  case (1):
    shortest_Span();
    break;
  case (2):
    longest_Span();
    break;
  case (3):
    vector_Full();
    break;
  case (4):
    big_Vector();
    break;
  default:
    shortest_Span();
    longest_Span();
    vector_Full();
    big_Vector();
  }
  return 0;
}
