#include "PmergeMe.hpp"
#include <cstddef>
#include <deque>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

PmergeMe::PmergeMe(int ac, char **av)
    : ac(ac), av(av)

{
  std::string const jacob(JACOBSTAHL_LIST);
  std::istringstream stringsStream(jacob);
  std::string line;
  while (std::getline(stringsStream, line, ' ')) {
    char *end_ptr = &line[0] + line.size();
    int value = std::strtol(line.c_str(), &end_ptr, 10);
    jacobstahl.push_back(value);
  }
}
PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
  if (this == &rhs)
    return (*this);
  this->vector = rhs.vector;
  this->deque = rhs.deque;
  this->sorted_vector = rhs.sorted_vector;
  this->sorted_deque = rhs.sorted_deque;
  return *this;
}

void PmergeMe::throw_error(errors e) {
  switch (e) {
  case (NOT_NUMBER):
    throw std::logic_error("Error: one of the inputs is not a number");
  case (EMPTY_INPUT):
    throw std::logic_error("Error: Empty input");
  case (NUMBER_TOO_BIG):
    throw std::logic_error("Error: number bigger than `int` found");
  case (DUPLICATE_NUMBER):
    throw std::logic_error("Error: duplicate number found");
  default:
    break;
  }
}
void PmergeMe::check_input() {
  int i = 1;
  int j = 0;

  bool all_empty = true;
  // check for all empty inputs
  while (i < ac && av[i]) {
    j = 0;
    while (av[i][j]) {
      if (av[i][j] != ' ')
        all_empty = false;
      j++;
    }
    i++;
  }
  if (all_empty)
    throw_error(EMPTY_INPUT);

  i = 1;
  j = 0;
  while (i < ac && av[i]) {
    j = 0;
    while (av[i][j]) {
      if (!(std::isdigit(av[i][j]) || av[i][j] == ' '))
        throw_error(NOT_NUMBER);
      j++;
    }
    i++;
  }
}

void PmergeMe::parse_into_containers() {
  for (int i = 1; i < ac; i++) {
    std::istringstream stringsStream(av[i]);
    std::string line;
    while (std::getline(stringsStream, line, ' ')) {
      if (!line.empty()) {
        char *end_ptr = &line[0] + line.size();
        long value = std::strtol(line.c_str(), &end_ptr, 10);
        if (value > std::numeric_limits<int>::max())
          throw_error(NUMBER_TOO_BIG);
        // throws error in case of duplicates
        checkDuplicates(vector, static_cast<int>(value));
        vector.push_back(static_cast<int>(value));
        deque.push_back(static_cast<int>(value));
      }
    }
  }
}

void PmergeMe::sort() {
  check_input();
  parse_into_containers();
  // printVector(vector);
  // printDeque(deque);
  // sort_vector();
  // sort_deque();
}

void PmergeMe::checkDuplicates(std::vector<int> v, int value) {
  if (std::find(v.begin(), v.end(), value) != v.end())
    throw_error(DUPLICATE_NUMBER);
}
