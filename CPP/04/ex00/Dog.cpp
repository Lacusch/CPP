#include "Dog.hpp"

Dog::Dog() {
  std::cout << "Dog constructor called" << std::endl;
  type = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog &a) {
  type = a.getType();
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return *this;
}

std::string const &Dog::getType() const {
  std::cout << "Dog getType() called" << std::endl;
  return this->type;
}

void Dog::makeSound() const { std::cout << "BARK, BARK !!" << std::endl; }
