#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
class Weapon {
public:
  const std::string &getType();
  void setType(const std::string newType);
  Weapon(std::string name);
  ~Weapon();

private:
  std::string _type;
};
#endif
