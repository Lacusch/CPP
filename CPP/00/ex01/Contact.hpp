#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iomanip>
#include <iostream>
#include <string>

class Contact {
public:
  Contact();
  ~Contact();
  void get_info();
  void print_elements();
  std::string *get_element(int i);

private:
  std::string _F_Name;
  std::string _L_Name;
  std::string _Nickname;
  std::string _Phone;
  std::string _dark_secret;
};
#endif
