#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
PmergeMe::PmergeMe(int ac, char **av)
    : ac(ac), av(av), has_odd(false), odd_number(-1) {}
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
        long value = strtol(line.c_str(), &end_ptr, 10);
        if (value > 2147483647)
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
  std::vector<int> const &j_vector =
      build_sequence<std::vector<int> >(vector.size() / 2);
  std::deque<int> const &j_deque =
      build_sequence<std::deque<int> >(vector.size() / 2);
  printVector(vector, 'b');
  clock_t start_vector = std::clock();
  sort_vector(vector, j_vector);
  clock_t end_vector = std::clock();
  printVector(sorted_vector, 'a');
  print_time_diff(start_vector, end_vector, 'v');
  clock_t start_deque = std::clock();
  sort_deque(deque, j_deque);
  clock_t end_deque = std::clock();
  print_time_diff(start_deque, end_deque, 'd');
}

void PmergeMe::checkDuplicates(std::vector<int> v, int value) {
  if (std::find(v.begin(), v.end(), value) != v.end())
    throw_error(DUPLICATE_NUMBER);
}

void PmergeMe::sort_vector(std::vector<int> &original_vector,
                           const std::vector<int> j_vector) {
  if (original_vector.size() == 0) {
    sorted_vector = original_vector;
    return;
  }
  // 1.
  // check if the list is odd or not
  if (original_vector.size() % 2 != 0) {
    has_odd = true;
    odd_number = original_vector.back();
    original_vector.pop_back();
  }
  // 2.
  // group the list into pairs
  std::vector<std::pair<int, int> > int_pair;
  for (size_t i = 0; i < original_vector.size() / 2; i++)
    int_pair.push_back(
        std::make_pair(original_vector[2 * i], original_vector[2 * i + 1]));
  // sort the newly created pairs
  for (size_t i = 0; i < int_pair.size(); i++) {
    if (int_pair[i].first < int_pair[i].second)
      std::swap(int_pair[i].first, int_pair[i].second);
  }
  // 3.
  // sort the pairs iteratively with binary sort
  std::vector<std::pair<int, int> > sorted_pairs;
  for (size_t i = 0; i < original_vector.size() / 2; i++) {
    if (i == 0)
      sorted_pairs.push_back(int_pair[i]);
    else {
      int position = bSearchPairs(sorted_pairs, int_pair[i].first, 0,
                                  sorted_pairs.size() - 1);
      ;
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
    int jacob_pos = j_vector[i] - 1;
    int value = sorted_pairs[jacob_pos].second;
    int position = bSearch(main_chain, value, 0, main_chain.size());
    main_chain.insert(main_chain.begin() + position, value);
  }
  // handle odd number
  if (has_odd && odd_number >= 0) {
    int position = bSearch(main_chain, odd_number, 0, main_chain.size() - 1);
    main_chain.insert(main_chain.begin() + position, odd_number);
  }
  sorted_vector = main_chain;
  this->has_odd = false;
  this->odd_number = -1;
}

void PmergeMe::sort_deque(std::deque<int> &original_deque,
                          const std::deque<int> j_deque) {
  if (original_deque.size() == 0) {
    sorted_deque = original_deque;
    return;
  }
  // 1.
  // check if the list is odd or not
  if (original_deque.size() % 2 != 0) {
    has_odd = true;
    odd_number = original_deque.back();
    original_deque.pop_back();
  }
  // 2.
  // group the list into pairs
  std::deque<std::pair<int, int> > int_pair;
  for (size_t i = 0; i < original_deque.size() / 2; i++)
    int_pair.push_back(
        std::make_pair(original_deque[2 * i], original_deque[2 * i + 1]));
  // sort the newly created pairs
  for (size_t i = 0; i < int_pair.size(); i++) {
    if (int_pair[i].first < int_pair[i].second)
      std::swap(int_pair[i].first, int_pair[i].second);
  }
  // 3.
  // sort the pairs iteratively with binary sort
  std::deque<std::pair<int, int> > sorted_pairs;
  for (size_t i = 0; i < original_deque.size() / 2; i++) {
    if (i == 0)
      sorted_pairs.push_back(int_pair[i]);
    else {
      int position = bSearchPairs(sorted_pairs, int_pair[i].first, 0,
                                  sorted_pairs.size() - 1);
      ;
      sorted_pairs.insert(sorted_pairs.begin() + position, int_pair[i]);
    }
  }
  // 4. i.
  // create the main chain (so take the first elements of the sorted pairs,
  // sorted[i].first and make a vector out of them)
  std::deque<int> main_chain;
  for (size_t i = 0; i < int_pair.size(); i++) {
    main_chain.push_back(sorted_pairs[i].first);
  }
  // 4 ii.
  // use binary insertion on the Jacobstahl Numbers
  for (size_t i = 0; i < int_pair.size(); i++) {
    int jacob_pos = j_deque[i] - 1;
    int value = sorted_pairs[jacob_pos].second;
    int position = bSearch(main_chain, value, 0, main_chain.size());
    main_chain.insert(main_chain.begin() + position, value);
  }
  // handle odd number
  if (has_odd && odd_number >= 0) {
    int position = bSearch(main_chain, odd_number, 0, main_chain.size() - 1);
    main_chain.insert(main_chain.begin() + position, odd_number);
  }
  sorted_deque = main_chain;
  this->has_odd = false;
  this->odd_number = -1;
}

void PmergeMe::print_time_diff(clock_t start, clock_t end, char c) {
  clock_t res;
  std::string micro = "\xC2\xB5";
  if (c == 'v')
    std::cout << "The time it took to sort Vector is : ";
  else if (c == 'd')
    std::cout << "The time it took to sort Deque is : ";
  res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
  if (res > 1000)
    std::cout << res / 1000 << "ms" << std::endl;
  else
    std::cout << res << micro << "s" << std::endl;
}
