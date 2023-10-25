#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
class RPN {
public:
  RPN();
  ~RPN();
  RPN(RPN const &rhs);
  RPN &operator=(RPN const &rhs);

private:
  std::stack<int> int_stack;
  std::string input;
};
#endif