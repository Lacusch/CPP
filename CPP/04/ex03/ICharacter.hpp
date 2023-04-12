#ifndef I_CHARACTER_HPP
#define I_CHARACTER_HPP
#include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter {
public:
  ICharacter();
  virtual ~ICharacter();
  ICharacter(const ICharacter &cpy);
  ICharacter &operator=(ICharacter const &rhs);
  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};
#endif
