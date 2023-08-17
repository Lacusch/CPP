#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <stdint.h>

#include "data.hpp"

class Serializer {
  // Rule of 3
 public:
  Serializer();
  ~Serializer();
  Serializer(Serializer const &cpy);
  Serializer &operator=(Serializer const &rhs);
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
#endif
