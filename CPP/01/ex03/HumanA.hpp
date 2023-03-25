#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include "Weapon.hpp"
#include <iostream>
/*
Has a reference to  weapon as it's already initiated at the start.
*/
class HumanA {
public:
  HumanA(std::string Name, Weapon &Weapon);
  ~HumanA();
  void attack();

private:
  std::string _Name;
  Weapon &_Weapon;
};
#endif
