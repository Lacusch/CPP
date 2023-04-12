#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#ifndef MAX_INVENTORY
#define MAX_INVENTORY 4
#endif
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character();
  ~Character();
  Character(const Character *cpy);
  Character &operator=(Character const &rhs);
  Character(std::string const &_name);
  virtual std::string const &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);

private:
  const std::string _name;
  AMateria *_Spells[MAX_INVENTORY];
  int _spellNb;
  void defaultInventory();
  void deleteSpells();
  void copySpells(Character const &src);
};
#endif
