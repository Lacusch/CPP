#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <cstdlib>
#include <iostream>
#include <string>
#include <system_error>
class Zombie {
private:
  std::string _Name;

public:
  void announce() const;
  Zombie(void);
  ~Zombie();
  void setZombieName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
