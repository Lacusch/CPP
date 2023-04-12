#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal(), _brain(new Brain) {
  std::cout << "Cat constructor called" << std::endl;
  type = "cat";
}

Cat::~Cat() {
  delete _brain;
  std::cout << "Cat destructor called" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &a) {
  type = a.getType();
  _brain = new Brain;
  *_brain = *a._brain;
}
// Copy assignment operator
Cat &Cat::operator=(const Cat &rhs) {
  if (this == &rhs)
    return *this;
  this->type = rhs.type;
  *_brain = *rhs._brain;
  return *this;
}

std::string const &Cat::getType() const { return this->type; }

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }

std::string const &Cat::getIdea(int i) const { return (_brain->getIdea(i)); }

void Cat::setIdea(int i, const std::string &idea) { _brain->setIdea(i, idea); }

void Cat::printIdeas() const { _brain->printIdeas(); }
