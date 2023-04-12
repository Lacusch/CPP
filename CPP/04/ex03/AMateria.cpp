#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {
  std::cout << "AMateria Default Constructor" << std::endl;
}

AMateria::~AMateria() {
  std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &cpy) {
  std::cout << "AMateria Parameterized Constructor called" << std::endl;
  *this = cpy;
}
AMateria &AMateria::operator=(const AMateria &rhs) {
  if (this == &rhs)
    return *this;
  this->type = rhs.getType();
  return *this;
}

AMateria::AMateria(std::string const &spell) : type(spell) {
  std::cout << "AMateria Parameterized Constructor" << std::endl;
}
std::string const &AMateria::getType() const { return type; }


void AMateria::use(ICharacter &target) {
  (void)target;
  return;
}
