#include "Dog.hpp"

Dog::Dog() {
  std::cout << "Dog constructor called" << std::endl;
  type = "dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog &a) {
  type = a.getType();
}

Dog &Dog::operator=(const Dog &rhs) {
  this->type = rhs.type;
  return *this;
}

std::string const &Dog::getType() const {
  return this->type;
}

void Dog::makeSound() const { std::cout << "BARK, BARK !!" << std::endl; }
