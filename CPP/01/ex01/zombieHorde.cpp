#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  Zombie *Horde;
  Horde = new Zombie[N];
  for (int i = 0; i < N + 1; i++) {
    Horde[i].setZombieName(name);
  }
  return Horde;
}
