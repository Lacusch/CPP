#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
  this->_name = "FragTrap v69";
  this->_hitPoints = F_TRAP_HP;
  this->_energyPoints = F_TRAP_EN;
  this->_attackDamage = F_TRAP_AT;
  this->_max_en = F_TRAP_EN;
  this->_max_hp = F_TRAP_HP;
}

FragTrap::FragTrap(std::string name) {
  this->_name = name;
  this->_hitPoints = F_TRAP_HP;
  this->_energyPoints = F_TRAP_EN;
  this->_attackDamage = F_TRAP_AT;
  this->_max_en = F_TRAP_EN;
  this->_max_hp = F_TRAP_HP;
  std::cout << "ClapTrap " << this->_name << " into a FragTrap with a bang"
            << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->_name
            << " devolved into ClapTrap, losing it's special explosion power"
            << std::endl;
}

FragTrap::FragTrap(FragTrap &cpy) : ClapTrap() {
  std::cout << "FragTrap Copy constructor called" << std::endl;
  *this = cpy;
}

FragTrap &FragTrap::operator=(const FragTrap &cpy) {
  std::cout << "ScavTrap Copy assignment operator called" << std::endl;
  this->_attackDamage = cpy._attackDamage;
  this->_energyPoints = cpy._energyPoints;
  this->_hitPoints = cpy._hitPoints;
  this->_name = cpy._name;
  this->_max_en = cpy._max_en;
  this->_max_hp = cpy._max_hp;
  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << this->_name
            << " has gave a high five to all the guys";
  if (this->_energyPoints < this->_max_en) {
    if (_energyPoints + 5 > this->_max_en) {
      this->_energyPoints = this->_max_en;
      std::cout << " Restoring his own energy points to the max"
                << this->_max_en << std::endl;
    } else {
      this->_energyPoints += 5;
      std::cout << " Restoring his own energy points by 5 to "
                << this->_energyPoints << std::endl;
    }
  } else {
    std::cout << " Raising his morale and making himself feel better" << std::endl;
  }
}
