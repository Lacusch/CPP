#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

int main(int ac, char **av) {
  int test = 0;
  if (ac != 1)
    test = atoi(av[1]);
  if (test == 0 || ac > 2) {
    std::cout << "Give the program a parameter, a number between 1-3" << std::endl
              << std::endl;
    std::cout << "n == 1: Normal Text" << std::endl;
    std::cout << "n == 2: Wronganimal and WrongCat text" << std::endl;
    std::cout << "n == 3: My own test" << std::endl;
    std::cout << "n > 3: All the test" << std::endl;
    return 1;
  }
  if (test == 1 || test > 3) {
    std::cout << "Normal test (from the pdf)" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    // new Dog();
    std::cout << "The type of this animal is: " << j->getType() << std::endl;
    std::cout << "The type of this animal is: " << i->getType() << std::endl;
    std::cout << "The type of this animal is: " << meta->getType() << std::endl;

    std::cout << "Sound of Cat:" << std::endl;
    i->makeSound(); // will output the cat sound!
    std::cout << "Sound of Dog:" << std::endl;
    j->makeSound();
    std::cout << "Sound of Animal:" << std::endl;
    meta->makeSound();
    delete j;
    delete meta;
    delete i;
    if (test < 4)
      system("leaks Animals");
  }
  if (test == 2 || test > 3) {
    if (test > 3)
      std::cout << std::endl << std::endl;
    std::cout << "Wrong animal test (from the pdf)" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const WrongAnimal *i = new WrongCat();
    std::cout << "The type of this animal is: " << j->getType() << std::endl;
    std::cout << "The type of this animal is: " << i->getType() << std::endl;
    std::cout << "The type of this animal is: " << meta->getType() << std::endl;
    std::cout << "Sound of Dog:" << std::endl;
    j->makeSound();
    std::cout << "Sound of WrongCat:" << std::endl;
    i->makeSound(); // will NOT output the cat sound!
    std::cout << "Sound of Animal:" << std::endl;
    meta->makeSound();
    delete j;
    delete meta;
    delete i;
    if (test < 4)
      system("leaks Animals");
  }
  if (test == 3 || test > 3) {
    if (test > 3)
      std::cout << std::endl << std::endl;
    std::cout << "My own test (a bit shitty but at least self made 😉)"
              << std::endl;
    const Dog *j = new Dog();
    const WrongAnimal *i = new WrongCat();
    std::cout << "The type of Dog is " << j->getType() << std::endl;
    std::cout << "And the sound it makes is: " << std::endl;
    j->makeSound();
    std::cout << "The type of WrongCat is " << i->getType() << std::endl;
    std::cout << "And the sound it makes is: " << std::endl;
    i->makeSound();
    std::cout << std::endl;
    delete j;
    delete i;
    if (test < 4)
      system("leaks Animals");
  }
  if (test > 3)
    system("leaks Animals");
  return 0;
}
