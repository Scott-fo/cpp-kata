#include "trie.cpp"
#include <gtest/gtest.h>

TEST(TrieTest, InsertAndSearch) {
  Trie trie;
  trie.insert("test");
  trie.insert("tent");
  trie.insert("testing");
  trie.insert("tang");
  trie.remove("tang");
  EXPECT_TRUE(trie.find("test"));
  EXPECT_TRUE(trie.find("tent"));
  EXPECT_TRUE(trie.find("testing"));
  EXPECT_FALSE(trie.find("tend"));
  EXPECT_FALSE(trie.find("tang"));
}
