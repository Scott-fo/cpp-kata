#ifndef BINARY_TREE_IN_ORDER_H
#define BINARY_TREE_IN_ORDER_H

#include "types.h"

#include <vector>

using std::vector;

inline void in_order_helper(BinaryNode<int> *node, vector<int> *result) {
  if (node == nullptr) {
    return;
  }

  if (node->left != nullptr) {
    in_order_helper(node->left, result);
  }

  result->push_back(node->value);

  if (node->right != nullptr) {
    in_order_helper(node->right, result);
  }
}

inline vector<int> in_order(BinaryNode<int> *head) {
  vector<int> result;

  in_order_helper(head, &result);

  return result;
}

#endif
