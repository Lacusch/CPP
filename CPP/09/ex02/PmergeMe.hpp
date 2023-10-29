#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP
#include <cmath>
#include <deque>
#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
enum errors { NOT_NUMBER, EMPTY_INPUT, NUMBER_TOO_BIG, DUPLICATE_NUMBER };

#define JACOBSTAHL_LIST                                                        \
  "1 3 2 5 7 17 31 65 127 257 511 1025 2047 4097 8191 16385 32767 \
65537 131071 262145 524287 1048577 2097151 4194305 8388607 \
16777217 33554431 67108865 134217727 268435457 536870911 \
1073741825 2147483647"

// "0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
// 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
// 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
// 1431655765"

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
  std::vector<int> jacobstahl;
  int bSearchVectorPairs(std::vector<std::pair<int, int> > vec_pair, int key,
                         int start, int end);
  int bSearchVector(const std::vector<int> &vector, int key, int start,
                    int end);
  void print_time_diff(clock_t start, clock_t end, char c);
  // print vector template
  template <typename T> void printVector(const std::vector<T> &vec, char c) {
    if (c == 'b')
      std::cout << "The elements before sorting" << std::endl;
    else if (c == 'a')
      std::cout << "The elements after sorting" << std::endl;
    else {
      std::cout << "Vector size is: " << vec.size() << std::endl;
      std::cout << "The elements before sorting" << std::endl;
    }
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