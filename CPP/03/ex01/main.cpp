#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ScavTrap t2;
  t2.guardGate();
  t2.takeDamage(111);
  t2.beRepaired(200);
  t2.attack("Target dummy");
  return 0;
}  
