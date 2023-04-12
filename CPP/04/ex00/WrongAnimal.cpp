#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wronganimal") {
  std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &a) : type(a.type) {
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  this->type = rhs.type;
  return *this;
}

std::string const &WrongAnimal::getType() const {
  return this->type;
}

void WrongAnimal::makeSound() const {
  std::cout
      << "Sounds of Wronganimal and, definitely not the sound of a Plant 😀"
      << std::endl;
}
