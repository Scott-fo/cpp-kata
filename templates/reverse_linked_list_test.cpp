#include "reverse_linked_list.cpp"

#include <gtest/gtest.h>

TEST(LinkedListTest, Reverse) {
  LinkedList<int> list;
  list.append(1);
  list.append(2);
  list.append(3);
  reverse(list);
  EXPECT_EQ(list.get(0), 3);
  EXPECT_EQ(list.get(1), 2);
  EXPECT_EQ(list.get(2), 1);
}
