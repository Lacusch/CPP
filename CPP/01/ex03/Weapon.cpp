#include "Weapon.hpp"

Weapon::Weapon(std::string name) : _type(name) {}
Weapon::~Weapon() {}
std::string const &Weapon::getType() { return this->_type; }
void Weapon::setType(std::string const newType) { _type = newType; }
