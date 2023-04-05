#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include <string>
#include <iostream>
#define CLAP_HP 10
#define CLAP_EN 10
#define CLAP_AT 0
class ClapTrap {
public:
  //Orthodox Canonical Form
  ClapTrap();
  ~ClapTrap();
  ClapTrap(ClapTrap &cpy);
  ClapTrap &operator=(const ClapTrap &cpy);
  // subject
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  ClapTrap(std::string name);
private:
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
  std::string _name;
};
#endif
