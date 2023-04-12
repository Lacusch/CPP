#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP
#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria {
protected:
  std::string type;

public:
  // Rule of 3
  // <https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)>

  // Constructor
  AMateria();
  // Destructor
  virtual ~AMateria();
  // Copy Constructor
  AMateria(const AMateria &cpy);
  // Copy assignment operator
  AMateria &operator=(const AMateria &rhs);
  // Parameterized Constructor
  AMateria(std::string const &spell);
  // getters
  std::string const &getType() const; // Returns the materia type
  // Member functions
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};
#endif
