#include "Zombie.hpp"

int main(void) {
  randomChump("Stack boi");
  Zombie *heap = newZombie("Heap boi");
  heap->announce();
  delete (heap);
  return 0;
}
