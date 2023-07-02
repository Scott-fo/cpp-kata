#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdexcept>
template <typename T> class ArrayList {
public:
  ArrayList() : length(0), capacity(1) { data = new int[0]; }

  ArrayList(int l) : length(l), capacity(l) { data = new T[l]; }

  void add(T element) {
    if (length == capacity) {
      capacity *= 2;

      T *newData = new T[capacity];
      for (int i = 0; i < length; ++i) {
        newData[i] = data[i];
      }

      data = newData;
    }

    data[length] = element;
    length++;
  }

  void remove(int index) {
    if (index >= length) {
      return;
    }

    for (int i = index; i < length - 1; ++i) {
      data[i] = data[i + 1];
    }

    length--;
  }

  T get(int index) {
    if (index >= length) {
      throw std::out_of_range("Index out of bounds");
    }

    return data[index];
  }

public:
  int length;

private:
  int capacity;
  T *data;
};

#endif
