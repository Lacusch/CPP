#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include <iostream>
#include <string>
class WrongAnimal {
public:
  // Orthodox Canonical Form
  WrongAnimal();
  ~WrongAnimal();
  WrongAnimal(const WrongAnimal &a);
  WrongAnimal &operator=(const WrongAnimal &rhs);
  // getter
  std::string const &getType() const;
  // member functions
  void makeSound() const;

protected:
  std::string type;
};
#endif