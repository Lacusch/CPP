#include "Harl.hpp"

Harl::Harl() {
  funcTable.f[0] = &Harl::_debug;
  funcTable.n[0] = "DEBUG";
  funcTable.f[1] = &Harl::_info;
  funcTable.n[1] = "INFO";
  funcTable.f[2] = &Harl::_warning;
  funcTable.n[2] = "WARNING";
  funcTable.f[3] = &Harl::_error;
  funcTable.n[3] = "ERROR";
}

Harl::~Harl(){};

void Harl::_debug(void) const {
  std::cout << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup "
               "burger. I really do!"
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
  std::cerr << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {
  for (size_t i = 0; i < funcTable.n->size(); i++) {
    if (!level.compare(funcTable.n[i])) {
      (this->*funcTable.f[i])();
      return;
    }
  }
  std::cout << "[ Probably complaining about insignificant problems ]"
            << std::endl;
}
