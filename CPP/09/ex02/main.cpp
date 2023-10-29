#include "PmergeMe.hpp"
#include <limits>

int main(int ac, char **av) {
  try {
    if (ac < 2)
      throw std::logic_error("Not enough arguments");
    PmergeMe sorter(ac, av);
    sorter.sort();
    // sorter.sort();
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}