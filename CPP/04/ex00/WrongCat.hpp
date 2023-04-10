#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP
#include "WrongAnimal.hpp"
#include <iostream>
class WrongCat : public WrongAnimal {
public:
  // Orthodox Canonical Form
  WrongCat();
  ~WrongCat();
  WrongCat(const WrongCat &a);
  WrongCat &operator=(const WrongCat &rhs);
  // getter
  std::string const &getType() const;
  // member functions
  void makeSound()const;
};
#endif
