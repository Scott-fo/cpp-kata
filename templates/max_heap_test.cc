#include "max_heap.h"
#include <gtest/gtest.h>

TEST(MaxHeapTest, InsertAndRemove) {
  MaxHeap maxHeap;
  maxHeap.insert(5);
  maxHeap.insert(3);
  maxHeap.insert(8);
  EXPECT_EQ(maxHeap.remove(), 8);
  EXPECT_EQ(maxHeap.remove(), 5);
  EXPECT_EQ(maxHeap.remove(), 3);
}
