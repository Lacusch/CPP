#include <string>
#include <iostream>

class Character {
public:
  void sayHello(std::string const & target);
};

class Warrior : public Character {
public:
  void sayHello(std::string const & target);
};

class Cat {
  //[...]
};

void Character::sayHello(const std::string &target) {
  std::cout << "Hello " << target << " ! " << std::endl;
}

void Warrior::sayHello(const std::string &target) {
  std::cout << "F*** off " << target << " , I dont' like you ! " << std::endl;
}

int main() {
  // This is OK, obviously, Warrior IS Warrior
  Warrior *a = new Warrior();

  // this is also OK because Warrior IS a Character
  Character *b = new Warrior;

  // This would NOT be ok because Warrior IS a Character
  // They're not even related
  // Character * d = new Cat();
  a->sayHello("students");
  b->sayHello("students");
  delete a;
  delete b; 
}