#include "min_heap.h"
#include <gtest/gtest.h>

TEST(MinHeapTest, InsertAndRemove) {
  MinHeap minHeap;
  minHeap.insert(5);
  minHeap.insert(3);
  minHeap.insert(8);
  EXPECT_EQ(minHeap.remove(), 3);
  EXPECT_EQ(minHeap.remove(), 5);
  EXPECT_EQ(minHeap.remove(), 8);
}
