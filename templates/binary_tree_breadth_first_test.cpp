#include "binary_tree.cpp"
#include "binary_tree_breadth_first.cpp"
#include <gtest/gtest.h>

TEST(BinaryTreeTest, BreadthFirstTraversal) {
  BinaryTree<int> tree;
  tree.root = new BinaryNode<int>(1);
  tree.root->left = new BinaryNode<int>(2);
  tree.root->right = new BinaryNode<int>(3);
  tree.root->left->left = new BinaryNode<int>(4);
  tree.root->left->right = new BinaryNode<int>(5);

  std::vector<int> traversal = breadth_first(tree.root);
  ASSERT_EQ(traversal.size(), 5);
  EXPECT_EQ(traversal[0], 1);
  EXPECT_EQ(traversal[1], 2);
  EXPECT_EQ(traversal[2], 3);
  EXPECT_EQ(traversal[3], 4);
  EXPECT_EQ(traversal[4], 5);
}
