#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap t1("BOB");
  t1.guardGate();
  std::cout << std::endl;
  t1.takeDamage(100);
  std::cout << std::endl;
  t1.guardGate();
  std::cout << std::endl;
  t1.guardGate();
  t1.attack("Dummy");
  t1.attack("Dummy2");
  std::cout << std::endl;
  t1.beRepaired(100);
  std::cout << std::endl;
  t1.highFivesGuys();
  std::cout << std::endl;
  t1.whoAmI();
  std::cout << std::endl;
  return 0;
}  
