#include "doubly_linked_list.h"
#include <gtest/gtest.h>

TEST(DoublyLinkedListTest, AddAndRemoveTest) {
  DoublyLinkedList<int> list;
  list.append(2);
  list.prepend(1);
  list.append(3);
  EXPECT_EQ(list.get(0), 1);
  EXPECT_EQ(list.get(1), 2);
  EXPECT_EQ(list.get(2), 3);
  list.remove(1);
  EXPECT_EQ(list.get(0), 1);
  EXPECT_EQ(list.get(1), 3);
}
