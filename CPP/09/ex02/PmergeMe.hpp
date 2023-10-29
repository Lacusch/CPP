#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP
#include <deque>
#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
enum errors { NOT_NUMBER, EMPTY_INPUT, NUMBER_TOO_BIG, DUPLICATE_NUMBER };

#define JACOBSTAHL_LIST                                                        \
  "2 1 5 7 17 31 65 127 257 511 1025 2047 4097 8191 16385 32767 \
65537 131071 262145 524287 1048577 2097151 4194305 8388607 \
16777217 33554431 67108865 134217727 268435457 536870911 \
1073741825 2147483647"

class PmergeMe {
private:
  int ac;
  char **av;
  bool has_odd;
  int odd_number;
  std::vector<int> vector;
  std::deque<int> deque;
  std::vector<int> sorted_vector;
  std::deque<int> sorted_deque;
  void check_input();
  void parse_into_containers();
  void parse_input();
  void sort_vector();
  void sort_deque();
  void throw_error(errors e);
  void checkDuplicates(std::vector<int> v, int value);
  void printDeque() const;
  std::vector<int> jacobstahl;

  // print vector template
  template <typename T> void printContainer(const std::vector<T> &vec) {
    std::cout << "Vector size is: " << vec.size()
              << " and it's elements are: " << std::endl;
    for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend();
         it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
  // print vector template
  template <typename T> void printVector(const std::vector<T> &vec) {
    std::cout << "Vector size is: " << vec.size()
              << " and it's elements are: " << std::endl;
    for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend();
         it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
  // print deque template
  template <typename T> void printDeque(const std::deque<T> &vec) {
    std::cout << "Deque size is: " << vec.size()
              << " and it's elements are: " << std::endl;
    for (std::deque<int>::const_iterator it = vec.cbegin(); it != vec.cend();
         it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

public:
  PmergeMe(int ac, char **av);
  ~PmergeMe();
  PmergeMe(PmergeMe const &rhs);
  PmergeMe &operator=(PmergeMe const &rhs);
  void sort();
};
#endif