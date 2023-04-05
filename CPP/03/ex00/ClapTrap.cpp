#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _hitPoints(CLAP_HP), _energyPoints(CLAP_EN), _attackDamage(CLAP_AT),
      _name("ClapTrap") {

  std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _hitPoints(CLAP_HP), _energyPoints(CLAP_EN), _attackDamage(CLAP_AT),
      _name(name) {
  std::cout << "ClapTrap constructor called with name:" << _name << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << this->_name << " Destructor called" << std::endl; }

ClapTrap::ClapTrap(ClapTrap &cpy) {
  std::cout << "ClapTrapCopy constructor called" << std::endl;
  *this = cpy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cpy) {
  std::cout << "ClapTrapCopy assignment operator called" << std::endl;
  this->_attackDamage = cpy._attackDamage;
  this->_energyPoints = cpy._energyPoints;
  this->_hitPoints = cpy._hitPoints;
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (_energyPoints == 0)
    std::cout << "Claptrap" << this->_name
              << " cannot attack because it's out of energy points"
              << std::endl;
  else {
    this->_energyPoints--;
    std::cout << "Claptrap " << this->_name
              << " has used up an energy point, it has " << this->_energyPoints
              << " remaining" << std::endl;
    std::cout << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage"
              << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "Claptrap " << _name
              << " cannot take any more damage as it's already broke"
              << std::endl;
  } else {
    if (this->_hitPoints <= amount) {
      _hitPoints = 0;
      std::cout << "Claptrap " << _name << " Broke down as it took " << amount
                << " points of damage"
                << " setting it to 0" << std::endl;
    } else {
      _hitPoints -= amount;
      std::cout << "Claptrap " << _name << " took " << amount
                << " of damage but still survived with " << _hitPoints << "HP"
                << std::endl;
    }
  }
}
void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_energyPoints == 0)
    std::cout << "Claptrap " << this->_name
              << " cannot heal because it's out of energy points" << std::endl;
  else if (amount == 0) {
    std::cout << "Claptrap " << this->_name << " cannot heal 0 HP" << std::endl;
  } else {
    if (this->_hitPoints == CLAP_HP)
      std::cout << "Claptrap " << this->_name
                << " cannot heal because it's already at max HP" << CLAP_HP
                << std::endl;
    else if (this->_hitPoints == 0) {
      this->_energyPoints--;
      if (amount > CLAP_HP)
        amount = CLAP_HP;
      this->_hitPoints += amount;
      std::cout << "Claptrap" << this->_name << " has used up an energy point, it has "
                << this->_energyPoints << "  remaining" << std::endl;
      std::cout << "Claptrap restored itself from broke down junk to "
                << this->_hitPoints << "HP and is able to do stuff normally again"
                << std::endl;
    } else if (amount + this->_hitPoints < CLAP_HP) {
      this->_energyPoints--;
      this->_hitPoints += amount;
      std::cout << "Claptrap " << this->_name << " has used up an energy point, it has "
                << this->_energyPoints << " remaining" << std::endl;
      std::cout << "Claptrap healed itself " << amount << "HP to "
                << this->_hitPoints << "HP" << std::endl;
    } else {
      this->_energyPoints--;
      std::cout << "Claptrap " << this->_name << " has used up an energy point, it has "
                << this->_energyPoints << " remaining" << std::endl;
      this->_hitPoints = CLAP_HP;
      std::cout << "Claptrap healed itself " << amount  << "HP to max HP" << CLAP_HP
                << std::endl;
    }
  }
}