#include "types.hh"

template <typename T> class BinaryTree {
public:
  BinaryNode<T> *root;

  BinaryTree() { root = nullptr; }
};
