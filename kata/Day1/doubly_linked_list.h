#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept>

template <typename T> struct Node {
  T data;
  Node *next;
  Node *prev;

  Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T> class DoublyLinkedList {
public:
  DoublyLinkedList() : length(0) {
    head = nullptr;
    tail = nullptr;
  }

  void prepend(T item) {
    Node<T> *node = new Node<T>(item);

    length++;

    if (head == nullptr) {
      head = tail = node;
      return;
    }

    node->next = head;
    head->prev = node;
    head = node;
  }

  void insert_at(T item, int index) {
    if (index > length) {
      throw std::out_of_range("Index out of range");
    }

    if (index == length) {
      append(item);
      return;
    }

    if (index == 0) {
      prepend(item);
      return;
    }

    length++;

    Node<T> *curr = get_at(index);
    Node<T> *node = new Node<T>(item);

    node->next = curr;
    node->prev = curr->prev;
    curr->prev = node;

    if (node->prev) {
      node->prev->next = node;
    }
  }

  void append(T item) {
    Node<T> *node = new Node<T>(item);

    length++;
    if (head == nullptr) {
      head = tail = node;
    }

    node->prev = tail;
    tail->next = node;
    tail = node;
  }

  T remove_at(int index) {
    if (index > length) {
      throw std::out_of_range("Index out of range");
    }

    Node<T> *curr = get_at(index);
    return remove_node(curr);
  }

  T remove(T item) {
    Node<T> *curr = head;
    for (int i = 0; curr && i < length; ++i) {
      if (curr->data == item) {
        break;
      }

      curr = curr->next;
    }

    if (!curr) {
      throw std::out_of_range("Item not found");
    }

    return remove_node(curr);
  }

  T get(int index) {
    if (index > length) {
      throw std::out_of_range("Index out of range");
    }

    Node<T> *node = get_at(index);
    return node->data;
  }

private:
  T remove_node(Node<T> *node) {
    length--;
    T out = node->data;

    if (node->prev) {
      node->prev->next = node->next;
    }

    if (node->next) {
      node->next->prev = node->prev;
    }

    if (node == head) {
      head = node->next;
    }

    if (node == tail) {
      tail = node->prev;
    }

    delete node;
    return out;
  }

  Node<T> *get_at(int index) {
    Node<T> *curr = head;

    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }

    return curr;
  }

public:
  int length;

private:
  Node<T> *head;
  Node<T> *tail;
};

#endif
