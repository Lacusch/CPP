#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>

ICharacter::ICharacter() {
  std::cout << "ICharacter Default Constructor" << std::endl;
}

ICharacter::~ICharacter() {
  std::cout << "ICharacter Destructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &src) {
  std::cout << "ICharacter copy constructor called" << std::endl;
  *this = src;
}

ICharacter &ICharacter::operator=(const ICharacter &rhs) {
  (void)rhs;
  return *this;
}
