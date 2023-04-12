#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>
class Animal {
public:
  // Orthodox Canonical Form
  Animal();
  virtual ~Animal();
  Animal(const Animal &a);
  Animal &operator=(const Animal &rhs);
  // getter
  virtual std::string const &getType() const;
  // member functions
  virtual void makeSound() const;

protected:
  std::string type;
};
#endif
