#include "Harl.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error" << std::endl << "Invalid number of arguments" << std::endl;
  }
  Harl NPC;
  if (ac == 2)
    NPC.complain(av[1]);
}
