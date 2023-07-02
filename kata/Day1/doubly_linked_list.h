#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T> class DoublyLinkedList {
public:
  DoublyLinkedList() {}

  void prepend(T item) {}

  void insert_at(T item, int index) {}

  void append(T item) {}

  T *remove(T item) {}
  T *remove_at(int index) {}

  T get(int index) {}

public:
  int length;
};

#endif
