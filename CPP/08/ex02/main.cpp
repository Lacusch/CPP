#include "MutantStack.tpp"
#include "iostream"

static void test_Iterators() {
  MutantStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  std::cout << "Using iterators to print elements: ";
  for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

static void test_Const_Iterators() {
  MutantStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  const MutantStack<int> &constStack = stack;
  std::cout << "Using const iterators to print elements: ";
  for (MutantStack<int>::const_iterator it = constStack.begin();
       it != constStack.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

static void test_Pop() {
  MutantStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  std::cout << "size of mutant stack is: " << stack.size() << std::endl;
  stack.pop();
  stack.pop();
  std::cout << "size should've decreased by two" << std::endl;
  std::cout << "size of mutant stack is: " << stack.size() << std::endl;
}

int main(int ac, char **av) {
  if (ac == 1 || ac > 2) {
    std::cerr << "Usage:" << std::endl;
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. test_Iterators" << std::endl
              << "2. test_Const_Iterators" << std::endl
              << "3. test_Pop" << std::endl
              << "5-n Run all tests🧪" << std::endl;
    return 1;
  }
  int arg = atoi(av[1]);
  if (arg < 1) {
    std::cerr << "Type the number for corresponding to the test(s) you want to "
                 "run"
              << std::endl
              << "1. test_Iterators" << std::endl
              << "2. test_Const_Iterators" << std::endl
              << "3. test_Pop" << std::endl
              << "4-n Run all tests🧪" << std::endl;
    return 1;
  }
  switch (arg) {
  case (1):
    test_Iterators();
    break;
  case (2):
    test_Const_Iterators();
    break;
  case (3):
    test_Pop();
    break;

  default:
    test_Iterators();
    test_Const_Iterators();
    test_Pop();
  }
  return 0;
}
