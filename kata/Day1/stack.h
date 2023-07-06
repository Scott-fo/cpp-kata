#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T> struct Node {
  T value;
  Node<T> *next;

  Node(T val) : value(val) { next = nullptr; }
};

template <typename T> class Stack {
public:
  Stack() : length(0) { head = nullptr; }

  void push(T item) {
    Node<T> *node = new Node<T>(item);
    node->next = head;
    head = node;
    length++;
  }

  T pop() {
    if (length == 0) {
      throw std::underflow_error("Length is 0");
    }

    Node<T> *node = head;
    T value = node->value;

    head = head->next;

    delete node;

    length--;

    return value;
  }

  T peek() {
    if (length == 0) {
      throw std::underflow_error("Length is 0");
    }

    return head->value;
  }

private:
  int length;
  Node<T> *head;
};

#endif
