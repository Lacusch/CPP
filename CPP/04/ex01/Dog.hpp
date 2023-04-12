#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
  // Orthodox Canonical Form
  Dog();
  virtual ~Dog();
  Dog(const Dog &a);
  Dog &operator=(const Dog &rhs);
  // getters
  virtual std::string const &getType() const;
  virtual std::string const &getIdea(int i) const;
  // setters
  virtual void setIdea(int i, std::string const &idea);
  // member functions
  virtual void makeSound() const;
  virtual void printIdeas() const;

private:
  Brain *_brain;
};
#endif
