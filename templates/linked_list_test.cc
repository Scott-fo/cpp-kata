#include "linked_list.h"
#include <gtest/gtest.h>

TEST(LinkedListTest, AddAndRemoveTest) {
  LinkedList<int> list;
  list.append(1);
  list.append(2);
  list.insert_at(3, 2);
  EXPECT_EQ(list.get(0), 1);
  EXPECT_EQ(list.get(1), 2);
  EXPECT_EQ(list.get(2), 3);
  list.remove(1);
  EXPECT_EQ(list.get(0), 1);
  EXPECT_EQ(list.get(1), 3);
}
