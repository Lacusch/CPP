#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP
#include "AMateria.hpp"
class IMateriaSource {
public:
  IMateriaSource();
  virtual ~IMateriaSource();
  IMateriaSource(IMateriaSource const &src);
  IMateriaSource &operator=(IMateriaSource const &rhs);

  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};
#endif
