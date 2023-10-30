#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP
#include <cmath>
#include <deque>
#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
enum errors { NOT_NUMBER, EMPTY_INPUT, NUMBER_TOO_BIG, DUPLICATE_NUMBER };

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
  void sort_vector(std::vector<int> &, const std::vector<int> j_vector);
  void sort_deque(std::deque<int> &original_deque,
                  const std::deque<int> j_deque);
  void throw_error(errors e);
  void checkDuplicates(std::vector<int> v, int value);
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
  template <typename Container> Container build_sequence(int b_len) {
    Container jacob_sequence;
    Container full_sequence;
    int jacob_index = 2;

    while (jacobsthal(jacob_index) < b_len + 2 - 1) {
      jacob_sequence.push_back(jacobsthal(jacob_index));
      jacob_index += 1;
    }
    for (size_t i = 0; i < jacob_sequence.size(); i++) {
      if (i == 0)
        full_sequence.push_back(jacob_sequence[i]);
      else {
        full_sequence.push_back(jacob_sequence[i]);
        int range = jacob_sequence[i] - jacob_sequence[i - 1] - 1;
        for (int j = 0; j < range; j++)
          full_sequence.push_back(jacob_sequence[i] - (j + 1));
      }
    }
    for (int i = 0; b_len > static_cast<int>(full_sequence.size()); i++)
      full_sequence.push_back(jacob_sequence[jacob_sequence.size() - 1] + i +
                              1);
    return (full_sequence);
  }
  template <typename number> number jacobsthal(number n) {
    if (n == 0)
      return (0);
    if (n == 1)
      return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
  }
  template <typename Container>
  int bSearch(const Container &c, int key, int start, int end) {
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (c[mid] == key) {
        return mid;
      } else if (c[mid] < key) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return start;
  }
  template <typename Container>
  int bSearchPairs(Container c_pair, int key, int start, int end) {
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (c_pair[mid].first == key) {
        return mid;
      } else if (c_pair[mid].first < key) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return start;
  }

public:
  PmergeMe(int ac, char **av);
  ~PmergeMe();
  PmergeMe(PmergeMe const &rhs);
  PmergeMe &operator=(PmergeMe const &rhs);
  void sort();
};
#endif