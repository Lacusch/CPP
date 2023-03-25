#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
#include "Weapon.hpp"
#include <iostream>
/*
Has a pointer to a weapon, as that is null-able.
*/
class HumanB {
public:
  HumanB(std::string Name);
  ~HumanB();
  void attack();
  void setWeapon(Weapon &currentWeapon);

private:
  std::string _Name;
  Weapon *currentWeapon;
};
#endif
