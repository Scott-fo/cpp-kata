#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <algorithm>
#include <stdexcept>

template <typename T> class ArrayList {
public:
  ArrayList() : length(0), capacity(1) { data = new T[1](); }

  ArrayList(int l) : length(l), capacity(l) { data = new T[l](); }

  // Rule of 5
  ~ArrayList() { delete[] data; }

  ArrayList(const ArrayList &other)
      : length(other.length), capacity(other.capacity) {
    data = new T[capacity];
    std::copy(other.data, other.data + length, data);
  }

  ArrayList(ArrayList &&other) noexcept
      : length(other.length), capacity(other.capacity), data(other.data) {
    other.length = 0;
    other.capacity = 0;
    other.data = nullptr;
  }

  ArrayList &operator=(const ArrayList &other) {
    if (this != &other) {
      delete[] data;

      length = other.length;
      capacity = other.capacity;
      data = new T[capacity];
      std::copy(other.data, other.data + length, data);
    }

    return *this;
  }

  ArrayList &operator=(ArrayList &&other) noexcept {
    if (this != &other) {
      delete[] data;

      length = other.length;
      capacity = other.capacity;
      data = other.data;

      other.length = 0;
      other.capacity = 0;
      other.data = nullptr;
    }

    return *this;
  }
  //

  void add(T element) {
    if (length == capacity) {
      capacity *= 2;

      T *newData = new T[capacity];
      for (int i = 0; i < length; ++i) {
        newData[i] = data[i];
      }

      delete[] data;
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

    if (length < capacity / 4) {
      capacity /= 2;

      T *newData = new T[capacity];
      for (int i = 0; i < length; ++i) {
        newData[i] = data[i];
      }

      delete[] data;
      data = newData;
    }
  }

  T get(int index) const {
    if (index >= length) {
      throw std::out_of_range("Index out of bounds");
    }

    return data[index];
  }

  T &operator[](int index) {
    if (index >= length || index < 0) {
      throw std::out_of_range("Index out of bounds");
    }

    return data[index];
  }

  int size() const { return length; }

private:
  int length;
  int capacity;
  T *data;
};

#endif
