#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Cure : public AMateria {
public:
  Cure();
  ~Cure();
  Cure(const Cure &cpy);
  Cure &operator=(const Cure &rhs);
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};
#endif
