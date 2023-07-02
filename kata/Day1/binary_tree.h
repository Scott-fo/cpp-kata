#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "types.h"

template <typename T> class BinaryTree {
public:
  BinaryTree() { root = nullptr; }

  BinaryTree(T v) { root = new BinaryNode<T>(v); }

  ~BinaryTree() { clear(root); }

  void insert(T value) {
    if (root == nullptr) {
      root = new BinaryNode<T>(value);
    } else {
      insert_helper(root, value);
    }
  }

private:
  void insert_helper(BinaryNode<T> *node, T value) {
    if (value < node->value) {
      if (node->left == nullptr) {
        node->left = new BinaryNode<T>(value);
      } else {
        insert_helper(node->left, value);
      }
    } else {
      if (node->right == nullptr) {
        node->right = new BinaryNode<T>(value);
      } else {
        insert_helper(node->right, value);
      }
    }
  }

  void clear(BinaryNode<T> *node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

public:
  BinaryNode<T> *root;
};

#endif
