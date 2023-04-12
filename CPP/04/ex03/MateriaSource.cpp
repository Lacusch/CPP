#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : IMateriaSource(), _spellNb(0) {
  std::cout << "MateriaSource Default Constructor" << std::endl;
  defaultInventory();
}

MateriaSource::MateriaSource(const std::string &name)
    : _name(name), _spellNb(0) {
  std::cout << "MateriaSource Parameterized Constructor" << std::endl;
  defaultInventory();
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource Destructor" << std::endl;
  defaultInventory();
}

MateriaSource::MateriaSource(const MateriaSource &src) {
  defaultInventory();
  *this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  if (this == &rhs)
    return *this;
  defaultInventory();
  for (int i = 0; i < MAX_INVENTORY; i++) {
    _Spells[i] = rhs._Spells[i]->clone();
  }
  _spellNb = rhs._spellNb;
  return *this;
}

void MateriaSource::learnMateria(AMateria *s) {
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (_Spells[i] == NULL) {
      _Spells[i] = s;
      _spellNb++;
      return;
    }
  }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (type == _Spells[i]->getType()) {
      return _Spells[i]->clone();
    }
  }
  return NULL;
}

void MateriaSource::deleteSpells() {
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (_Spells[i] != NULL) {
      delete _Spells[i];
      _Spells[i] = NULL;
    }
  }
}

void MateriaSource::defaultInventory() {
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (_Spells[i] != NULL)
        _Spells[i] = NULL;
  }
}
