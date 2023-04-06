#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include <iostream>
#include <string>
#define C_CLAP_HP 10
#define C_CLAP_EN 10
#define C_CLAP_AT 0
class ClapTrap {
public:
  // Orthodox Canonical Form
  ClapTrap();
  ~ClapTrap();
  ClapTrap(ClapTrap &cpy);
  ClapTrap &operator=(const ClapTrap &cpy);
  // subject
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  ClapTrap(std::string name);
  std::string & getName(void);
protected:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
  bool guard_mode;
  unsigned int _max_hp;
  unsigned int _max_en;

private:

};
#endif
