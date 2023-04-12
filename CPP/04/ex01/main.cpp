#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>

// int main() {
//   Cat *d = new Cat();
//   std::string test = "test stuff";
//   std::cout << "Dog type is: " << std::endl << d->getType() << std::endl;
//   std::cout << std::endl;
//   d->makeSound();
//   d->setIdea(1, test);
//   d->setIdea(2, "new stuff");
//   d->printIdeas();
//   return 0;
// }

int main(int ac, char **av) {
  int test = 0;
  if (ac != 1)
    test = atoi(av[1]);
  if (test == 0 || ac > 2) {
    std::cout << "Give the program a parameter, a number between 1-3"
              << std::endl
              << std::endl;
    std::cout << "n == 1: Normal Text" << std::endl;
    std::cout << "n == 2: Wronganimal and WrongCat text" << std::endl;
    std::cout << "n == 3: My own test" << std::endl;
    std::cout << "n > 3: All the test" << std::endl;
    return 1;
  }
  if (test == 1 || test > 3) {
    std::cout << "Normal test (from the pdf)" << std::endl;
    const Animal *animals[8];
    for (int i = 0; i < 4; i++) {
      animals[i] = new Dog;
    }
    for (int i = 4; i < 8; i++) {
      animals[i] = new Cat;
    }
    for (int i = 0; i < 8; i++) {
      delete(animals[i]);
    }
    system("leaks Animals");
  }
  if (test == 2 || test > 3) {
    if (test > 3)
      std::cout << std::endl << std::endl;
  }
  if (test == 3 || test > 3) {

  }
  return 0;
}