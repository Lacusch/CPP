#include "Zombie.hpp"

int main(int ac, char **av) {

  int hordeSize;
  if (ac > 2) {
    std::cerr << "Error\nTo many arguments" << std::endl;
    return 1;
  } else if (ac < 2) {
    std::cout << "No horde size, using the default 42" << std::endl;
    hordeSize = 42;
  } else {
    hordeSize = std::atoi(av[1]);
    if (hordeSize == 0) {
      std::cerr << "Error\nSmall or invalid value, please try again!"
                << std::endl;
      return 1;
    }
  }
  Zombie *horde = zombieHorde(hordeSize, "Chump");
  for (int i = 0; i < hordeSize; i++) {
    std::cout << "zombie " << i + 1 << ": ";
    horde[i].announce();
  }
  delete[] horde;
  // system("leaks zombieHorde");
  return 0;
}
