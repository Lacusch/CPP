#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"
#define F_TRAP_HP 100
#define F_TRAP_EN 100
#define F_TRAP_AT 30
class FragTrap : virtual public ClapTrap {
public:
  // Orthodox Canonical Form
  FragTrap();
  ~FragTrap();
  FragTrap(FragTrap &cpy);
  FragTrap &operator=(const FragTrap &cpy);
  //
  FragTrap(std::string name);
  void highFivesGuys(void);
};
#endif
