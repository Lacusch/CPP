#include <cstdlib>
#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(int ac, char **av) {
  int test = 0;
  if (ac != 1)
    test = atoi(av[1]);
  if (test == 0 || ac > 2) {
    std::cout << "Give the program a parameter, a number between 1-3"
              << std::endl
              << std::endl;
    std::cout << "n == 1: Normal test from the pdf" << std::endl;
    std::cout << "n == 2: Testing unequip works or not" << std::endl;
    std::cout << "n == 3: Testing Deep copies of Dog" << std::endl;
    return 1;
  }
  if (test == 1 || test > 2) {
    std::cout << "Normal test (from the pdf)"
              << std::endl;
      IMateriaSource *src = new MateriaSource();
      src->learnMateria(new Ice());
      src->learnMateria(new Cure());
      ICharacter *me = new Character("me");
      AMateria *tmp;
      tmp = src->createMateria("ice");
      me->equip(tmp);
      tmp = src->createMateria("cure");
      me->equip(tmp);
      ICharacter *bob = new Character("bob");
      me->use(0, *bob);
      me->use(1, *bob);
      delete bob;
      delete me;
      delete src;
    if (test < 3)
      system("leaks Interface");
  }
  if (test == 2 || test > 2) {
    if (test > 2)
      std::cout << std::endl << std::endl;
    std::cout << "Testing unequip / use works as intended works or not" << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(1);
    delete bob;
    delete me;
    delete src;
    if (test < 3)
      system("leaks Interface");
  }
  if (test > 2)
    system("leaks Interface");
  return 0;
}