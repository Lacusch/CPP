#include <sys/_types/_uintptr_t.h>

#include "Serializer.hpp"
#include "data.hpp"
#include "iostream"

int main() {
  uintptr_t pointer;
  Serializer s;
  Data* to_serialize = new Data;
  Data* deserialized;
  to_serialize->name = "Rob";
  to_serialize->id = 12;
  std::cout << "Data is: " << to_serialize->id << std::endl
            << to_serialize->name << std::endl;
  std::cout << "Serializing data" << std::endl;
  pointer = s.serialize(to_serialize);
  std::cout << "Serialized data: " << pointer << std::endl;
  std::cout << "Deserializing data" << std::endl;
  deserialized = s.deserialize(pointer);
  std::cout << "Deserialized data is: " << to_serialize->id << std::endl
            << to_serialize->name << std::endl;
  delete to_serialize;
  return 0;
}