#include "bubble_sort.cpp"
#include <gtest/gtest.h>

TEST(BubbleSortTest, SortTest) {
  int data[10] = {2, 5, 3, 8, 4, 2, 9, 1, 7, 6};
  bubble_sort(data);
  for (int i = 0; i < 9; ++i) {
    EXPECT_LE(data[i], data[i + 1]);
  }
}
