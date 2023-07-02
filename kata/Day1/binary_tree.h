#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "types.h"

template <typename T> class BinaryTree {
public:
  BinaryNode<T> *root;

  BinaryTree() { root = nullptr; }
};

#endif
