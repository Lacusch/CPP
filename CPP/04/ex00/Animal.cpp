#include "Animal.hpp"

Animal::Animal() : type("animal") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &a) : type(a.type) {
}

Animal &Animal::operator=(const Animal &rhs) {
  this->type = rhs.type;
  return *this;
}

std::string const &Animal::getType() const {
  return this->type;
}

void Animal::makeSound() const {
  std::cout << "Sounds of and animal, definitely not the sound of a Plant 😀"
            << std::endl;
}
