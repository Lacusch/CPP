#include "WrongCat.hpp"

WrongCat::WrongCat() {
  std::cout << "WrongCat constructor called" << std::endl;
  type = "Wrongcat";
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat &a) {
  type = a.getType();
  std::cout << "WrongCatWrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  this->type = rhs.type;
  return *this;
}

std::string const &WrongCat::getType() const {
  std::cout << "WrongCat getType() called" << std::endl;
  return this->type;
}

void WrongCat::makeSound() const { std::cout << "Meow" << std::endl; }
