#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "types.hh"

template <typename T> class BinaryTree {
public:
  BinaryNode<T> *root;

  BinaryTree() { root = nullptr; }
};

#endif
