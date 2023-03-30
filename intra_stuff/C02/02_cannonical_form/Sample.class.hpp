#ifndef SAMPLE_CLASS_HPP
#define SAMPLE_CLASS_HPP
#include <ostream>
class Sample {
public:
  Sample();                             // Canonical form
  ~Sample();                            // Canonical form
  Sample(Sample const &str);            // Canonical form
  Sample &operator=(Sample const &rhs); // Canonical form

  Sample(int const n);
  int getFoo()const;
private:
  int _foo;
};
//Not canonical but used pretty often.
std::ostream &operator<<(std::ostream &o, Sample const &i);

#endif
