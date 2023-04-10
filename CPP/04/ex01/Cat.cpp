#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal(), _brain(new Brain) {
  std::cout << "Cat constructor called" << std::endl;
  type = "cat";
}

Cat::~Cat() {
  delete _brain;
  std::cout << "Cat destructor called" << std::endl;
}

// change for brain
Cat::Cat(const Cat &a) {
  type = a.getType();
  std::cout << "Cat copy constructor called" << std::endl;
}
// change for brain
Cat &Cat::operator=(const Cat &rhs) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return *this;
}

std::string const &Cat::getType() const {
  std::cout << "Cat getType() called" << std::endl;
  return this->type;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
