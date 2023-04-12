#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure Default Constructor" << std::endl;
}

Cure::~Cure() { std::cout << "Cure Destructor called" << std::endl; }

Cure::Cure(const Cure &cpy) {
  std::cout << "Cure Parameterized Constructor called" << std::endl;
  *this = cpy;
}

Cure &Cure::operator=(const Cure &rhs) {
  if (this == &rhs)
    return *this;
  this->type = rhs.getType();
  return *this;
}

AMateria *Cure::clone() const {
  AMateria *clone = new Cure();
  return clone;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals" << target.getName() << "’s wounds *" << std::endl;
}
