#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap::DiamondTrap()
    : ClapTrap("Diamond Trap 9000_clap_name") {
  ClapTrap::_name = "Diamond Trap 9000_clap_name";
  DiamondTrap::_name = "Diamond Trap 9000";
  FragTrap::_hitPoints = F_TRAP_HP;
  ScavTrap::_energyPoints = S_CLAP_EN;
  FragTrap::_attackDamage = F_TRAP_AT;
  FragTrap::_max_en = S_CLAP_EN;
  ScavTrap::_max_en = F_TRAP_HP;
  std::cout << "ClapTrap has evolved into a FragTrap with a bang" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
  ClapTrap::_name = (name + "_clap_name");
  DiamondTrap::_name = name;
  FragTrap::_hitPoints = F_TRAP_HP;
  ScavTrap::_energyPoints = S_CLAP_EN;
  FragTrap::_attackDamage = F_TRAP_AT;
  FragTrap::_max_en = F_TRAP_EN;
  ScavTrap::_max_en = F_TRAP_HP;
  std::cout << "ClapTrap has evolved into a FragTrap with a bang" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "Diamond Trap is breaking into it's component parts"
            << std::endl;
}
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
  std::cout << "DiamondTrap copy assignment operator called, assigning "
            << rhs._name << std::endl;
  if (this == &rhs)
    return *this;
  ClapTrap::operator=(rhs);
  DiamondTrap::_name = rhs.DiamondTrap::_name;
  return *this;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
  *this = cpy;
  return;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "I am a DiamondTrap, my name is " << DiamondTrap::_name
            << ". My ClapTrap name is " << ClapTrap::getName() << std::endl;
}
