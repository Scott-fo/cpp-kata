#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
template <typename T> struct Node {
  T value;
  Node<T> *next;

  Node(T val) : value(val) { next = nullptr; }
};

template <typename T> class LinkedList {
public:
  LinkedList() : length(0) { head = nullptr; }

  void insert_at(T item, int index) {
    if (index > length) {
      throw std::out_of_range("Index out of bounds");
    }

    if (index == 0) {
      prepend(item);
      return;
    }

    Node<T> *node = new Node<T>(item);
    Node<T> *curr = get_at(index - 1);

    length++;

    node->next = curr->next;
    curr->next = node;
  }

  void prepend(T item) {
    Node<T> *node = new Node<T>(item);

    length++;

    node->next = head;
    head = node;
  }

  T remove(T item) {
    Node<T> *prev_node = nullptr;
    Node<T> *curr_node = head;

    while (curr_node != nullptr && curr_node->value != item) {
      prev_node = curr_node;
      curr_node = curr_node->next;
    }

    if (curr_node == nullptr) {
      throw std::out_of_range("Item not found");
    }

    return remove_node(prev_node, curr_node);
  }

  T remove_at(int index) {
    if (index > length) {
      throw std::out_of_range("Index out of bounds");
    }

    Node<T> prev_node = nullptr;
    Node<T> curr_node = head;

    for (int i = 0; i < index; ++i) {
      prev_node = curr_node;
      curr_node = curr_node->next;
    }

    return remove_node(prev_node, curr_node);
  }

  T get(int index) {
    if (index > length) {
      throw std::out_of_range("Index out of bounds");
    }

    Node<T> *curr = head;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }

    return curr->value;
  }

  Node<T> *get_head() { return head; }

  void set_head(Node<T> *new_head) { head = new_head; }

private:
  Node<T> *get_at(int index) {
    Node<T> *curr = head;

    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }

    return curr;
  }

  T remove_node(Node<T> *prev_node, Node<T> *node_to_remove) {
    if (prev_node != nullptr) {
      prev_node->next = node_to_remove->next;
    } else {
      head = node_to_remove->next;
    }

    T out = node_to_remove->value;
    delete node_to_remove;

    length--;

    return out;
  }

public:
  int length;

private:
  Node<T> *head;
};

#endif
