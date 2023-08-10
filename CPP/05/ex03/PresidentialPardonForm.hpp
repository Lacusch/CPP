#ifndef PARDON_HPP
#define PARDON_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(std::string const &target);
  virtual void execute(Bureaucrat const &executor) const;
  std::string const &get_Target() const;

private:
  std::string const _target;
};
#endif
