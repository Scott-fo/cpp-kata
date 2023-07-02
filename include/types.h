#ifndef TYPES_H
#define TYPES_H

template <typename T> struct BinaryNode {
  T value;
  BinaryNode<T> *left;
  BinaryNode<T> *right;

  BinaryNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

struct Point {
  int x;
  int y;
};

#endif
