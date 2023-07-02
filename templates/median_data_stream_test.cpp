#include "median_data_stream.cpp"
#include <gtest/gtest.h>
#include <vector>

TEST(MedianDataStreamTest, BasicOperations) {
  std::vector<int> stream = {1, 2, 3, 4, 5};

  // Test median calculation
  EXPECT_EQ(calculate_median(stream), 3);

  // Adding more values to the stream
  stream.push_back(6);
  stream.push_back(7);

  // Test new median
  EXPECT_EQ(calculate_median(stream), 4);
}
