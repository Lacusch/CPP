#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _Name(name) { currentWeapon = nullptr; }

HumanB::~HumanB(){};

void HumanB::attack() {
  if (currentWeapon != nullptr)
    std::cout << _Name << " attacks with their " << currentWeapon->getType()
              << std::endl;
  else
    std::cout << _Name
              << "has the daunting reallisation that attacking without a weapon"
                 "is inpossible😭"
              << std::endl;
  ;
}
void HumanB::setWeapon(Weapon &newWeapon) { currentWeapon = &newWeapon; }
