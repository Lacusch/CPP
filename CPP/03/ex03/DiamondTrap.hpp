#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {
public:
  // Orthodox Canonical Form
  DiamondTrap();
  ~DiamondTrap();
  DiamondTrap(DiamondTrap const &cpy);
  DiamondTrap &operator=(const DiamondTrap &cpy);
  //
  DiamondTrap(std:: string _name);
  void whoAmI();
  void attack(std::string const &target);

private:
  std::string _name;
};
#endif
