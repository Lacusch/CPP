#include "Cat.hpp"

Cat::Cat() {
  std::cout << "Cat constructor called" << std::endl;
  type = "cat";
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &a) {
  type = a.getType();
  std::cout << "CatCat copy constructor called" << std::endl;
}

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
