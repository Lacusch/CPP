#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(), _brain(new Brain) {
  std::cout << "Dog constructor called" << std::endl;
  type = "Dog";
}

Dog::~Dog() {
  delete _brain;
  std::cout << "Dog destructor called" << std::endl;
}

//change for brain
Dog::Dog(const Dog &a) {
  type = a.getType();
  std::cout << "Dog copy constructor called" << std::endl;
}
// change for brain
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
