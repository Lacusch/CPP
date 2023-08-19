#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>

template <typename T> int easyfind(T &container, int value) {
  typename T::iterator result =
      std::find(container.begin(), container.end(), value);

  if (result == container.end()) {
    return -1; // Return a specific error value indicating value not found
  }

  return std::distance(container.begin(), result);
}

#endif
