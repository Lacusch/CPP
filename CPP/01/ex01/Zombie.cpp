#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
  std::cout << "Zombie:\"" << this->_Name
            << "\" has rooten away and returned to the"
            << " ground where we all came from" << std::endl;
}

void Zombie::announce() const {
  std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName(std::string name) { this->_Name = name; }
