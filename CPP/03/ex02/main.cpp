#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
  FragTrap t1;
  t1.attack("Dummy");
  t1.attack("Dummy");
  t1.attack("Dummy");
  t1.attack("Dummy");
  t1.attack("Dummy");
  t1.attack("Dummy");
  t1.highFivesGuys();
  t1.takeDamage(14);
  t1.beRepaired(11);
  return 0;
}  
