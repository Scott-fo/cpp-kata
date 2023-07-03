#ifndef BINARY_TREE_POST_ORDER_H
#define BINARY_TREE_POST_ORDER_H

#include "types.h"

#include <vector>

using std::vector;

inline void post_order_helper(BinaryNode<int> *node, vector<int> *result) {
  if (node == nullptr) {
    return;
  }

  if (node->left != nullptr) {
    post_order_helper(node->left, result);
  }

  if (node->right != nullptr) {
    post_order_helper(node->right, result);
  }

  result->push_back(node->value);
}

inline vector<int> post_order(BinaryNode<int> *head) {
  vector<int> result;
  post_order_helper(head, &result);

  return result;
}

#endif
