#include "reverse_linked_list.h"

#include <gtest/gtest.h>

TEST(LinkedListTest, Reverse) {
  LinkedList<int> list;
  list.prepend(3);
  list.prepend(2);
  list.prepend(1);
  reverse(list);
  EXPECT_EQ(list.get(0), 3);
  EXPECT_EQ(list.get(1), 2);
  EXPECT_EQ(list.get(2), 1);
}
