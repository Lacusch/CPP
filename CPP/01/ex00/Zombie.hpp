#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>
class Zombie {
private:
  std::string _Name;

public:
  void announce() const;
  Zombie(std::string name);
  ~Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
