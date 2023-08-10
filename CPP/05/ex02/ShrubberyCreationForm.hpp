#include "AForm.hpp"
#include "Bureacrat.hpp"

class ShrubberyCreationForm : AForm{
public:
    ShrubberyCreationForm(std::string const & target);
    virtual void execute(Bureaucrat const & executor) const;
    std::string const & get_Target() const;
  private:
    std::string const _target;
};
