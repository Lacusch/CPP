
#include <iostream>
#include <string>

class ACharacter {
public:
  virtual void
  attack(std::string const &target) = 0; // Pure Method, doesn't exist
  void sayHello(std::string const &target);
};

class Warrior : public ACharacter {
public:
  virtual void attack(std::string const &target);
};

void ACharacter::sayHello(const std::string &target) {
  std::cout << "Hello " << target << std::endl;
}

void Warrior::attack(const std::string &target) {
  std::cout << "*attacks " << target << " with a greatsword*" << std::endl;
}

class ICoffeMaker {
public:
  virtual void fillWaterTank(std::string & waterSource) = 0;
};

int main() {
    ACharacter * a = new Warrior();
    //This would not work as ACharacter is abstract
    //ACharacter * b = new ACharacter

    a->sayHello("students");
    a->attack("bob");
    return 0;
}
