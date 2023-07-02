#include "stack.cpp"
#include <gtest/gtest.h>

TEST(StackTest, PushPop) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  EXPECT_EQ(stack.pop(), 3);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.pop(), 1);
}

TEST(StackTest, Underflow) {
  Stack<int> stack;
  EXPECT_THROW(stack.pop(), std::underflow_error);
}
