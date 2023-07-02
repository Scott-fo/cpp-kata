#ifndef BINARY_TREE_BREADTH_FIRST_H
#define BINARY_TREE_BREADTH_FIRST_H

#include "types.h"
#include <queue>
#include <vector>

using std::vector;

inline vector<int> breadth_first(BinaryNode<int> *head) {
  vector<int> result;
  std::queue<BinaryNode<int> *> queue;

  if (head == nullptr) {
    return result;
  }

  queue.push(head);
  do {
    BinaryNode<int> *node = queue.front();
    queue.pop();
    result.push_back(node->value);

    if (node->left != nullptr) {
      queue.push(node->left);
    }

    if (node->right != nullptr) {
      queue.push(node->right);
    }

  } while (!queue.empty());

  return result;
}

#endif
