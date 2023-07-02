#include "array_list.h"
#include <gtest/gtest.h>

TEST(ArrayListTest, AddAndGet) {
  ArrayList<int> arrayList;
  arrayList.add(1);
  arrayList.add(2);
  arrayList.add(3);
  EXPECT_EQ(arrayList.get(0), 1);
  EXPECT_EQ(arrayList.get(1), 2);
  EXPECT_EQ(arrayList.get(2), 3);
}

TEST(ArrayListTest, Remove) {
  ArrayList<int> arrayList;
  arrayList.add(1);
  arrayList.add(2);
  arrayList.add(3);
  arrayList.remove(1);
  EXPECT_EQ(arrayList.get(0), 1);
  EXPECT_EQ(arrayList.get(1), 3);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
