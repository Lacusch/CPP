#include "WrongCat.hpp"

WrongCat::WrongCat() {
  std::cout << "WrongCat constructor called" << std::endl;
  type = "Wrongcat";
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat &a) {
  type = a.getType();
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  this->type = rhs.type;
  return *this;
}

std::string const &WrongCat::getType() const {
  return this->type;
}

void WrongCat::makeSound() const { std::cout << "Meow" << std::endl; }
