#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Ice : public AMateria {
public:
  Ice();
  ~Ice();
  Ice(const Ice &cpy);
  Ice &operator=(const Ice &rhs);
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};
#endif
