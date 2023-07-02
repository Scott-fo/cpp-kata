#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "types.h"

template <typename T> class BinaryTree {
public:
  BinaryTree() { root = nullptr; }

  void insert(T value);

public:
  BinaryNode<T> *root;
};

#endif
