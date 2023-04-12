#include "Animal.hpp"

Animal::Animal() : type("animal") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &a) : type(a.type) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
  std::cout << "Animal copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return *this;
}

std::string const &Animal::getType() const {
  std::cout << "Animal getType() called" << std::endl;
  return this->type;
}
