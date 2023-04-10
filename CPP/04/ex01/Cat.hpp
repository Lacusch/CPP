
#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
class Cat : public Animal {
public:
  // Orthodox Canonical Form
  Cat();
  virtual ~Cat();
  Cat(const Cat &a);
  Cat &operator=(const Cat &rhs);
  // getter
  virtual std::string const &getType() const;
  // member functions
  virtual void makeSound()const;
private:
  Brain * _brain;  
};
#endif
