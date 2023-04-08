#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wronganimal") {
  std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &a) : type(a.type) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return *this;
}

std::string const &WrongAnimal::getType() const {
  std::cout << "WrongAnimal getType() called" << std::endl;
  return this->type;
}

void WrongAnimal::makeSound() const {
  std::cout << "Sounds of and Wronganimal, definitely not the sound of a Plant 😀"
            << std::endl;
}
