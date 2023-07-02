#include "map.h"
#include <gtest/gtest.h>
#include <string>

TEST(MapTest, PutAndGet) {
  Map<std::string, int> map;
  map.put("key1", 1);
  map.put("key2", 2);
  map.put("key3", 3);
  map.put("key4", 4);
  map.remove("key4");
  EXPECT_EQ(map.size(), 3);
  EXPECT_EQ(map.get("key1"), 1);
  EXPECT_EQ(map.get("key2"), 2);
  EXPECT_EQ(map.get("key3"), 3);
}

TEST(MapTest, KeyNotFound) {
  Map<std::string, int> map;
  EXPECT_THROW(map.get("key1"), std::out_of_range);
}
