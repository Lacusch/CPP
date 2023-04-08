#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
class Dog : public Animal {
  public:
  // Orthodox Canonical Form
  Dog();
  virtual ~Dog();
  Dog(const Dog &a);
  Dog &operator=(const Dog &rhs);
  // getters
  virtual std::string const &getType() const;
  // member functions
  virtual void makeSound() const;
};
#endif
