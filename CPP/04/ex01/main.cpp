#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

int main(int ac, char **av) {
  int test = 0;
  if (ac != 1)
    test = atoi(av[1]);
  if (test == 0 || ac > 2) {
    std::cout << "Give the program a parameter, a number between 1-3"
              << std::endl
              << std::endl;
    std::cout << "n == 1: Deletion of Animals with pointers" << std::endl;
    std::cout << "n == 2: Testing Deep copies of Cat" << std::endl;
    std::cout << "n == 3: Testing Deep copies of Dog" << std::endl;
    std::cout << "n  > 3: All the test" << std::endl;
    return 1;
  }
  if (test == 1 || test > 3) {
    if (test > 3)
      std::cout << std::endl << std::endl;
    std::cout << "Testing deletion of Animals with pointers (from the pdf)"
              << std::endl;
    const Animal *animals[8];
    for (int i = 0; i < 4; i++) {
      animals[i] = new Dog;
    }
    for (int i = 4; i < 8; i++) {
      animals[i] = new Cat;
    }
    for (int i = 0; i < 8; i++) {
      delete (animals[i]);
    }
    if (test < 3)
      system("leaks Animals");
  }
  if (test == 2 || test > 3) {
    if (test > 3)
      std::cout << std::endl << std::endl;
    std::cout << "Testing if Cat has deep copies" << std::endl;
    Cat *c1 = new Cat;
    c1->setIdea(1, "Cat");
    c1->setIdea(2, "Harass owner for food");
    std::cout << "Printing Ideas of Cat 1" << std::endl;
    c1->printIdeas();
    std::cout << std::endl << "Creating Cat 2 based on Cat 1" << std::endl;
    Cat *c2 = new Cat(*c1);
    std::cout << "Add a new Idea to Cat 2" << std::endl;
    c2->setIdea(3, "MOUSE ?!");
    std::cout << std::endl;
    std::cout << "Ideas of Cat 1: " << std::endl;
    c1->printIdeas();
    std::cout << "Ideas of Cat 2: " << std::endl;
    c2->printIdeas();
    std::cout << std::endl;
    delete c1;
    delete c2;
    if (test < 4)
      system("leaks Animals");
  }
  if (test == 3 || test > 3) {
    std::cout << "Testing if Dog has deep copies" << std::endl;
    Dog *d1 = new Dog;
    d1->setIdea(1, "Dog");
    d1->setIdea(2, "Play with owner");
    std::cout << "Printing Ideas of Dog 1" << std::endl;
    d1->printIdeas();
    std::cout << std::endl << "Creating Dog 2 based on Dog 1" << std::endl;
    Dog *d2 = new Dog(*d1);
    std::cout << "Add a new Idea to Dog 2" << std::endl;
    d2->setIdea(3, "CAT ?!?!?!?!?!?");
    std::cout << std::endl;
    std::cout << "Ideas of Dog 1: " << std::endl;
    d1->printIdeas();
    std::cout << "Ideas of Dog 2: " << std::endl;
    d2->printIdeas();
    std::cout << std::endl;
    delete d1;
    delete d2;
    if (test < 4)
      system("leaks Animals");
  }
  if (test > 3)
    system("leaks Animals");
  return 0;
}
