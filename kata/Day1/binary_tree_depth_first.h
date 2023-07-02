#ifndef BINARY_TREE_DEPTH_FIRST_H
#define BINARY_TREE_DEPTH_FIRST_H

#include "types.h"

#include <vector>

using std::vector;

inline vector<int> depth_first(BinaryNode<int> *head) {
  vector<int> result;

  vector<BinaryNode<int> *> stack;

  if (head == nullptr) {
    return result;
  }

  stack.push_back(head);

  do {
    BinaryNode<int> *node = stack.back();
    stack.pop_back();

    result.push_back(node->value);

    if (node->right != nullptr) {
      stack.push_back(node->right);
    }

    if (node->left != nullptr) {
      stack.push_back(node->left);
    }

  } while (!stack.empty());

  return result;
}

#endif
