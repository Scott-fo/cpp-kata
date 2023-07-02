#include "binary_search.cpp"
#include <gtest/gtest.h>

TEST(BinarySearchTest, ElementFound) {
  int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(binary_search(data, 5), true);
}

TEST(BinarySearchTest, ElementNotFound) {
  int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(binary_search(data, 11), false);
}
