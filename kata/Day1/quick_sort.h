#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

inline int partition(std::vector<int> &arr, int low, int high) {
  int mid = low + (high - low) / 2;

  int pivotIndex;
  if ((arr[low] > arr[mid]) ^ (arr[low] > arr[high]))
    pivotIndex = low;
  else if ((arr[mid] < arr[low]) ^ (arr[mid] < arr[high]))
    pivotIndex = mid;
  else
    pivotIndex = high;

  std::swap(arr[pivotIndex], arr[high]);

  int pivotValue = arr[high];

  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (arr[j] < pivotValue) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  i++;
  std::swap(arr[i], arr[high]);
  return i;
}

inline void quick_sort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    int pivotIndex = partition(arr, low, high);

    quick_sort(arr, low, pivotIndex - 1);
    quick_sort(arr, pivotIndex + 1, high);
  }
}

inline void quick_sort(std::vector<int> &arr) {
  quick_sort(arr, 0, arr.size() - 1);
}

#endif
