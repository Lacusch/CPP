#include "Serializer.hpp"

#include <sys/_types/_uintptr_t.h>

#include "data.hpp"

Serializer::Serializer(){};

Serializer::~Serializer(){};

Serializer::Serializer(Serializer const& cpy) { *this = cpy; }

Serializer& Serializer::operator=(Serializer const& rhs) {
  if (this != &rhs) *this = rhs;
  return *this;
};

uintptr_t Serializer::serialize(Data* ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
};

Data* Serializer::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data*>(raw));
}
