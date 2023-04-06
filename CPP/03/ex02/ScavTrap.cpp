#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

ScavTrap::ScavTrap() : ClapTrap(){
  this->_name = "ScavTrap v0";
  this->_hitPoints = S_CLAP_HP;
  this->_energyPoints = S_CLAP_EN;
  this->_attackDamage = 20;
  this->_max_hp = S_CLAP_HP;
  this->_max_en = S_CLAP_EN;
  std::cout << "ClapTrap evolved into ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
  this->_name = name;
  this->_hitPoints = S_CLAP_HP;
  this->_energyPoints = S_CLAP_EN;
  this->_attackDamage = 20;
  this->_max_hp = S_CLAP_HP;
  this->_max_en = S_CLAP_EN;
  std::cout << "ClapTrap " << this->_name << " Evolved into ScavTrap"
            << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->_name << " devolved into ClapTrap"
            << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &cpy) : ClapTrap() {
  std::cout << "ScavTrap Copy constructor called" << std::endl;
  *this = cpy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpy) {
  std::cout << "ScavTrap Copy assignment operator called" << std::endl;
  this->_attackDamage = cpy._attackDamage;
  this->_energyPoints = cpy._energyPoints;
  this->_hitPoints = cpy._hitPoints;
  this->_name = cpy._name;
  return *this;
}

void ScavTrap::guardGate() {
  if (this->guard_mode == true) {
    this->guard_mode = false;
    std::cout << "ScavTrap " << this->_name << " has exited guard mode"
              << std::endl;
  } else if (this->_energyPoints > 0) {
    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name
              << " has used up an energy point, it has " << this->_energyPoints
              << " remaining" << std::endl;
    this->guard_mode = true;
    std::cout
        << "ScavTrap " << this->_name
        << " has entered guard mode, taking reduced damage while it's active"
        << std::endl;
  } else {
    std::cout << "ScavTrap " << this->_name
    << " Cannot enter guardian mode as it's out of energy"
    << std::endl;
  }
}