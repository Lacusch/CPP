#include "Cat.hpp"

Cat::Cat() {
  std::cout << "Cat constructor called" << std::endl;
  type = "cat";
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &a) {
  type = a.getType();
}

Cat &Cat::operator=(const Cat &rhs) {
  this->type = rhs.type;
  return *this;
}

std::string const &Cat::getType() const {
  return this->type;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
