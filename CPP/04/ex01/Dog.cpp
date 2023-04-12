#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(), _brain(new Brain) {
  std::cout << "Dog constructor called" << std::endl;
  type = "Dog";
}

Dog::~Dog() {
  delete _brain;
  std::cout << "Dog destructor called" << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &a) {
  type = a.getType();
  _brain = new Brain;
  *_brain = *a._brain;
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &rhs) {
  if (this == &rhs)
    return *this;
  this->type = rhs.type;
  *_brain = *rhs._brain;
  return *this;
}

std::string const &Dog::getType() const {
  return this->type;
}

void Dog::makeSound() const { std::cout << "BARK, BARK !!" << std::endl; }

std::string const &Dog::getIdea(int i) const { return (_brain->getIdea(i)); }

void Dog::setIdea(int i, const std::string &idea) { _brain->setIdea(i, idea); }

void Dog::printIdeas() const { _brain->printIdeas(); }
