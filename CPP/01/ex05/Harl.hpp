#include <iostream>
#include <string>
#include <system_error>
class Harl {
public:
  Harl();
  ~Harl();
  void complain(std::string level);

private:
  void _debug(void) const;
  void _info(void) const;
  void _warning(void) const;
  void _error(void) const;
  typedef struct Funtions {
    void (Harl::*f[4])(void) const;
    std::string n[4];
  } Funtions;
  Funtions funcTable;
};
