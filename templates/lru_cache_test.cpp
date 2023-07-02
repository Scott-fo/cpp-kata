#include "lru_cache.cpp"
#include <gtest/gtest.h>
#include <string>

TEST(LRUCacheTest, BasicOperations) {
  LRU<std::string, int> lru;

  // Test updating the cache
  lru.update("one", 1);
  lru.update("two", 2);
  lru.update("three", 3);

  // Test getting values
  EXPECT_EQ(*lru.get("one"), 1);
  EXPECT_EQ(*lru.get("two"), 2);
  EXPECT_EQ(*lru.get("three"), 3);

  // Update value
  lru.update("one", 10);
  EXPECT_EQ(*lru.get("one"), 10);

  // Check LRU eviction
  lru.update("four", 4);              // Assuming max size of cache is 3
  EXPECT_EQ(lru.get("one"), nullptr); // "one" should have been evicted
}
