#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#ifndef MAX_INVENTORY
#define MAX_INVENTORY 4
#endif
#include "IMateriaSource.hpp"
#include <string>
class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const std::string &name);
  virtual ~MateriaSource();
  MateriaSource(const MateriaSource &src);
  MateriaSource &operator=(const MateriaSource &rhs);
  virtual void learnMateria(AMateria *);
  virtual AMateria *createMateria(std::string const &type);

private:
  const std::string _name;
  AMateria *_Spells[MAX_INVENTORY];
  int _spellNb;
  void defaultInventory();
  void deleteSpells();
};
#endif
