#include "binary_tree.h"
#include "types.h"
#include <gtest/gtest.h>

TEST(BinaryTreeTest, NodeCreation) {
  BinaryNode<int> *node = new BinaryNode<int>(1);
  EXPECT_EQ(node->value, 1);
  EXPECT_EQ(node->left, nullptr);
  EXPECT_EQ(node->right, nullptr);
}

TEST(BinaryTreeTest, TreeCreation) {
  BinaryTree<int> tree;
  EXPECT_EQ(tree.root, nullptr);
}
