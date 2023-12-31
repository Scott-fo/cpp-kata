#include "quick_sort.h"
#include <gtest/gtest.h>
#include <vector>

TEST(QuickSortTest, Sort) {
  std::vector<int> arr = {3, 2, 1, 5, 4};
  quick_sort(arr);
  for (int i = 0; i < 5 - 1; i++) {
    EXPECT_LE(arr[i], arr[i + 1]);
  }
}
