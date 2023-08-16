#ifndef IDENTITY_HPP
#define IDENTITY_HPP
#include "Base.hpp"
class Identity {
 public:
  Identity();
  ~Identity();
  Identity(Identity const& cpy);
  Identity& operator=(Identity const& rhs);
  // required functions

  Base* generate(void);
  static void identify(Base* p);
  static void identify(Base& p);
};
#endif
