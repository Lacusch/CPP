#ifndef SCALAR_HPP
#define SCALAR_HPP
#include "string"

// enum type { EMPTY, INVALID, LITERAL, NB, CHAR };
enum type { CHAR, LITERAL, NB, EMPTY, INVALID };
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
  // parse.cpp

  int static parse_String(std::string &input);
  bool static only_Space(std::string const &string);
  std::string static trim_Space(std::string &to_Trim);
  bool static invalid_Space(std::string const &string);
  bool static is_Lit(std::string const &string);
  bool static is_Nb(std::string &string);
  bool static is_Char(std::string const &string);
};
#endif
