#include "Character.hpp"
#include <iostream>

Character::Character() : _spellNb(0) {
  std::cout << "Character Default Constructor" << std::endl;
  defaultInventory();
}

Character::Character(std::string const &_name) : _name(_name), _spellNb(0) {
  std::cout << "Character Parameterized Constructor" << std::endl;
  defaultInventory();
}

Character::~Character() {
  std::cout << "Character Destructor" << std::endl;
  deleteSpells();
}

Character &Character::operator=(const Character &rhs) {
  if (this == &rhs)
    return *this;
  _spellNb = rhs._spellNb;
  copySpells(rhs);
  deleteSpells();
  copySpells(rhs);
  return *this;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  if (_spellNb > 3)
    return;
  _Spells[_spellNb] = m;
  _spellNb++;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= MAX_INVENTORY)
    return;
  _Spells[idx] = NULL;
  --_spellNb;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx >= MAX_INVENTORY)
    return;
  if (_Spells[idx] != NULL)
    _Spells[idx]->use(target);
}

// Private helper Functions

void Character::defaultInventory() {
  for (int i = 0; i < MAX_INVENTORY; i++) {
    _Spells[i] = NULL;
  }
}

void Character::deleteSpells() {
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (_Spells[i] != NULL) {
      delete _Spells[i];
      _Spells[i] = NULL;
    }
  }
}

void Character::copySpells(Character const &src) {
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (_Spells[i] != NULL) {
      _Spells[i] = src._Spells[i]->clone();
    }
  }
}
