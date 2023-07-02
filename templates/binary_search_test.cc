#include "binary_search.h"
#include <gtest/gtest.h>

TEST(BinarySearchTest, ElementFound) {
  std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(binary_search(data, 5), true);
}

TEST(BinarySearchTest, ElementNotFound) {
  std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(binary_search(data, 11), false);
}
