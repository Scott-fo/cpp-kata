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

TEST(BinaryTreeTest, InsertNode) {
  BinaryTree<int> tree;
  tree.insert(5);
  EXPECT_NE(tree.root, nullptr);
  EXPECT_EQ(tree.root->value, 5);
  tree.insert(3);
  EXPECT_NE(tree.root->left, nullptr);
  EXPECT_EQ(tree.root->left->value, 3);
  tree.insert(7);
  EXPECT_NE(tree.root->right, nullptr);
  EXPECT_EQ(tree.root->right->value, 7);
}
