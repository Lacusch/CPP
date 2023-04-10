#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>
#include <system_error>
class Brain {
public:
  // Orthodox Canonical Form
  Brain();
  ~Brain();
  Brain(const Brain &cpy);
  Brain &operator=(const Brain &b);
  // Method functions
  void printIdeas() const;
  void setIdea(int index, std::string const &idea);
  std::string const &getIdea(int i) const;

private:
  static const int _brainSize = 100;
  std::string ideas[_brainSize];
};
#endif
