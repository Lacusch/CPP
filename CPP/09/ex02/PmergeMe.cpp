#include "PmergeMe.hpp"
#include <cstddef>
#include <deque>
#include <fstream>
#include <stdexcept>
#include <string>
#include <utility>
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

void PmergeMe::sort_vector() {
  if (vector.size() == 0) {
    sorted_vector = vector;
    return;
  }
  // 1.
  // check if the list is odd or not
  if (vector.size() % 2 != 0) {
    has_odd = true;
    odd_number = vector.back();
    vector.pop_back();
  }
  // 2.
  // group the list into pairs
  std::vector<std::pair<int, int>> int_pair;
  for (size_t i = 0; i < vector.size() / 2; i++)
    int_pair.push_back(std::make_pair(2 * i, 2 * i + 1));
  // sort he newly created pairs
  for (size_t i = 0; i < int_pair.size(); i++) {
    if (int_pair[i].first > int_pair[i].second)
      std::swap(int_pair[i].first, int_pair[i].second);
  }
  // 3.
  // sort the pairs iteratively with binary sort
  std::vector<std::pair<int, int>> sorted_pairs;
  for (size_t i = 0; i < int_pair.size(); i++) {
    if (i == 0)
      sorted_pairs.push_back(int_pair[i]);
    else {
      int position = bSearchVectorPairs(sorted_pairs, sorted_pairs[i].first, 0,
                                        sorted_pairs.size() - 1);
      sorted_pairs.insert(sorted_pairs.begin() + position, int_pair[i]);
    }
  }
  // 4. i.
  // create the main chain (so take the first elements of the sorted pairs,
  // sorted[i].first and make a vector out of them)
  std::vector<int> main_chain;
  for (size_t i = 0; i < int_pair.size(); i++) {
    main_chain.push_back(sorted_pairs[i].first);
  }

  // 4 ii.
  // use binary insertion on the Jacobstahl Numbers
  for (size_t i = 0; i < int_pair.size(); i++) {
    int value = sorted_pairs[jacobstahl[i] - 1].second;
    int position = bSearchVector(main_chain, value, 0, main_chain.size());
  }
  // handle odd number
  sorted_vector = main_chain;
}

int PmergeMe::bSearchVectorPairs(
    const std::vector<std::pair<int, int>> &vec_pair, int key, int start,
    int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (vec_pair[mid].first == key) {
      return mid;
    } else if (vec_pair[mid].first < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return start;
}

int PmergeMe::bSearchVector(const std::vector<int> &vector, int key, int start,
                            int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (vector[mid] == key) {
      return mid;
    } else if (vector[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return start;
}
