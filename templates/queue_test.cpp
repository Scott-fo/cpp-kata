#include "queue.cpp"
#include <gtest/gtest.h>

TEST(QueueTest, EnqueueDequeue) {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  EXPECT_EQ(queue.dequeue(), 1);
  EXPECT_EQ(queue.dequeue(), 2);
  EXPECT_EQ(queue.dequeue(), 3);
}

TEST(QueueTest, Underflow) {
  Queue<int> queue;
  EXPECT_THROW(queue.dequeue(), std::underflow_error);
}
