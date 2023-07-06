#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T> struct Node {
  T value;
  Node<T> *next;

  Node(T val) : value(val) { next = nullptr; }
};

template <typename T> class Queue {
public:
  Queue() : length(0) { head = tail = nullptr; }

  void enqueue(T item) {
    Node<T> *node = new Node<T>(item);

    length++;
    if (tail == nullptr) {
      head = tail = node;
      return;
    }

    tail->next = node;
    tail = node;
  }

  T dequeue() {
    if (head == nullptr) {
      throw std::underflow_error("Length of queue is 0");
    }

    Node<T> *node = head;
    T value = node->value;

    head = head->next;

    length--;
    delete node;

    if (length == 0) {
      tail = nullptr;
    }

    return value;
  }

  T peek() {
    if (head == nullptr) {
      throw std::underflow_error("Length of queue is 0");
    }

    return head->value;
  }

  int size() { return length; }

private:
  int length;
  Node<T> *head;
  Node<T> *tail;
};

#endif
