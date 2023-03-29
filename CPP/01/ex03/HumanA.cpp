#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon)
    : _Name(name), _Weapon(Weapon) {}
HumanA::~HumanA(){};
void HumanA::attack() {
  std::cout << _Name << " attacks with their " << _Weapon.getType()
            << std::endl;
}
