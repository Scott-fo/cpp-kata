#ifndef REVERSE_LINKED_LIST_H
#define REVERSE_LINKED_LIST_H

#include "linked_list.h"

inline Node<int> *reverse_helper(Node<int> *node) {
  if (node == nullptr || node->next == nullptr) {
    return node;
  }

  Node<int> *new_head = reverse_helper(node->next);
  node->next->next = node;
  node->next = nullptr;

  return new_head;
}

inline void reverse(LinkedList<int> &list) {
  Node<int> *head = list.get_head();
  Node<int> *new_head = reverse_helper(head);
  list.set_head(new_head);
}

#endif
