#include "Harl.hpp"

Harl::Harl() {
  _funcTable.f[0] = &Harl::_debug;
  _funcTable.n[0] = "DEBUG";
  _funcTable.f[1] = &Harl::_info;
  _funcTable.n[1] = "INFO";
  _funcTable.f[2] = &Harl::_warning;
  _funcTable.n[2] = "WARNING";
  _funcTable.f[3] = &Harl::_error;
  _funcTable.n[3] = "ERROR";
}

Harl::~Harl(){};

void Harl::_debug(void) const {
  std::cout << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup "
               "burger. I really do !"
            << std::endl;
}

void Harl::_info(void) const {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::_warning(void) const {
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years where as you started working here since last month."
      << std::endl;
}

void Harl::_error(void) const {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {
  int l;
  l = 4;
  for (size_t i = 0; i < _funcTable.n->size(); i++) {
    if (!level.compare(_funcTable.n[i])) {
      l = i;
    }
  }
  if (l != 4) {
    std::cout << "[ "<< _funcTable.n[l] << " ]" << std::endl;
  }
  switch (l) {
  case 0:
    (this->*_funcTable.f[0])();
  case 1:
    (this->*_funcTable.f[1])();
  case 2:
    (this->*_funcTable.f[2])();
  case 3:
    (this->*_funcTable.f[3])();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    break;
  }
}
