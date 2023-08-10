#include "AForm.hpp"
#include "Bureacrat.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(std::string const &target);
  virtual void execute(Bureaucrat const &executor) const;
  std::string const & getTarget() const;
private:
  std::string const _target;
};
