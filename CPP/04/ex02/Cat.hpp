
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
