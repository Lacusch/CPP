#ifndef SCAVENGER_TRAP_HPP
#define SCAVENGER_TRAP_HPP
#include "ClapTrap.hpp"
#define S_CLAP_HP 100
#define S_CLAP_EN 50
#define S_CLAP_AT 0
class ScavTrap : public ClapTrap {
public:
  // Orthodox Canonical Form
  ScavTrap();
  ~ScavTrap();
  ScavTrap(ScavTrap & cpy);
  ScavTrap &operator=(const ScavTrap &cpy);
  //
  ScavTrap(std::string name);
  void guardGate();
};
#endif
