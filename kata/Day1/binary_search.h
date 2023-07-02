#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <math.h>
#include <vector>

inline bool binary_search(std::vector<int> haystack, int needle) {
  int left = 0;
  int right = haystack.size() - 1;

  do {
    int pivot = floor((left + right) / 2);

    if (haystack[pivot] > needle) {
      right = pivot - 1;
    } else if (haystack[pivot] < needle) {
      left = pivot + 1;
    } else {
      return true;
    }
  } while (left <= right);

  return false;
}

#endif
