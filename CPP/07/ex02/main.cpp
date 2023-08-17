#include <ctime>
#include <exception>

#include "Array.hpp"
#include "iostream"

void static float_Array_Test(void) {
  try {
    std::cout << "Float array test" << std::endl;
    Array<float> f_Array(7);
    f_Array[0] = 1.1;
    f_Array[1] = 2.1;
    f_Array[2] = 3.1;
    f_Array[3] = 4.1;
    f_Array[4] = 5.1;
    f_Array[5] = 6.1;
    f_Array[6] = 7.1;
    for (unsigned int i = 0; i < f_Array.size(); ++i) {
      std::cout << f_Array[i] << " ";
    }
    std::cout << std::endl << std::endl;
  } catch (const std::exception& e) {
    std::cout << "ERROR: " << e.what() << std::endl;
  }
}

void static over_Index_Test(void) {
  std::cout << "Over index test, should throw an exception" << std::endl;
  try {
    Array<std::string> strings(4);
    strings[0] = "This should be fine";
    strings[1] = "Same as this";
    strings[2] = "This stuff is pretty boring to write";
    strings[3] = "last one, next should `throw`";
    strings[4] =
        "This should throw an exception, so you can't read this either "
        "way🤷🏻🤷🏻";
  } catch (std::exception& e) {
    std::cout << "ERROR: " << e.what() << std::endl;
  }
}

void static negative_Index_Test(void) {
  std::cout << "Try to create an array with negative index, should throw an "
               "exception"
            << std::endl;
  try {
    Array<int> invalid(-2);
  } catch (const std::exception& e) {
    std::cout << "ERROR: " << e.what() << std::endl;
  }
}

void static valid_Arrays_Test(void) {
  std::cout << "Testing with valid arrays (shouldn't `throw`)" << std::endl;
  try {
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl
              << std::endl;

    Array<> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl
              << std::endl;
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;
    intArray[3] = 40;
    intArray[4] = 50;

    std::cout << "Original(int) array: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      std::cout << intArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    Array<int> copyArray = intArray;
    intArray[0] = 100;
    intArray[1] = 200;
    std::cout << "Copied(int) array: ";
    for (unsigned int i = 0; i < copyArray.size(); ++i) {
      std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

  } catch (const std::exception& error) {
    std::cout << "ERROR: " << error.what() << std::endl;
  }
}
int main(int ac, char** av) {
  if (ac == 1 || ac > 2) {
    std::cerr << "Usage:" << std::endl;
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. float_Array_Test" << std::endl
              << "2. over_Index_Test" << std::endl
              << "3. negative_Index_Test" << std::endl
              << "4. valid_Arrays_Test" << std::endl
              << "5-n Run all tests🧪" << std::endl;
    return 1;
  }
  int arg = atoi(av[1]);
  if (arg < 1) {
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. float_Array_Test" << std::endl
              << "2. over_Index_Test" << std::endl
              << "3. negative_Index_Test" << std::endl
              << "4. valid_Arrays_Test" << std::endl
              << "5-n Run all tests🧪" << std::endl;
    return 1;
  }
  switch (arg) {
    case (1):
      float_Array_Test();
      break;
    case (2):
      over_Index_Test();
      break;
    case (3):
      negative_Index_Test();
      break;
    case (4):
      valid_Arrays_Test();
      break;
    default:
      float_Array_Test();
      over_Index_Test();
      negative_Index_Test();
      valid_Arrays_Test();
  }
  return 0;
}