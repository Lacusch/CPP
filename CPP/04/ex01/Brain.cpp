#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain Constructor called" << std::endl; }

Brain::~Brain() { std::cout << "Brain Destructor called" << std::endl; }

Brain::Brain(const Brain &cpy) { *this = cpy; }

Brain &Brain::operator=(const Brain &b) {
  if (this == &b)
    return *this;
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = b.getIdea(i);
  }
  return *this;
}

void Brain::printIdeas() const {
  for (int i = 0; i < _brainSize; i++) {
    if (ideas[i] != "")
      std::cout << "Idea " << i << " is: " << this->ideas[i] << std::endl;
  }
  std::cout << "Printing ideas" << std::endl;
}

void Brain::setIdea(int index, std::string const &idea) {
  if (index < 0 || index > _brainSize)
    std::cerr << "Invalid index, set idea failed" << std::endl;
  else
    ideas[index] = idea;
  std::cout << "set idea called" << std::endl;
}

std::string const &Brain::getIdea(int i) const {
  if (i < 0 || i > _brainSize) {
    std::cerr << "Invalid index, returning the first idea" << std::endl;
    i = 0;
  }
  return ideas[i];
}
