#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice Default Constructor" << std::endl;
}

Ice::~Ice() { std::cout << "Ice Destructor called" << std::endl; }

Ice::Ice(const Ice &cpy) {
  std::cout << "Ice Parameterized Constructor called" << std::endl;
  *this = cpy;
}

Ice &Ice::operator=(const Ice &rhs) {
  if (this == &rhs)
    return *this;
  this->type = rhs.getType();
  return *this;
}

AMateria *Ice::clone() const {
  AMateria *clone = new Ice();
  return clone;
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
