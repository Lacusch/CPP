#ifndef SCALAR_HPP
#define SCALAR_HPP
#include "string"

class Scalar {
public:
  Scalar();
  ~Scalar();
  Scalar(Scalar &cpy);
  Scalar &operator=(const Scalar &rhs);
  void static convert(std::string input);

private:
  bool static handle_Literal(std::string const &intput);
  void static convert_Char(std::string input);
};
#endif
