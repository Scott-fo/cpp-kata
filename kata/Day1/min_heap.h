#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <cmath>
#include <math.h>
#include <stdexcept>
#include <vector>

class MinHeap {
public:
  MinHeap() : length(0) {}

  void insert(int value) {
    data.push_back(value);
    heapify_up(length);
    length++;
  }

  int remove() {
    if (length == 0) {
      throw std::underflow_error("Heap is empty");
    }

    int out = data[0];
    length--;

    if (length == 0) {
      data.clear();
      return out;
    }

    data[0] = data.back();
    data.pop_back();
    heapify_down(0);

    return out;
  }

  int peek() { return data.front(); }

private:
  void heapify_up(int i) {
    if (i == 0) {
      return;
    }

    int parent_index = get_parent_index(i);
    int parent_val = data[parent_index];

    int current_val = data[i];

    if (parent_val > current_val) {
      std::swap(data[i], data[parent_index]);
      heapify_up(parent_index);
    }
  }

  void heapify_down(int i) {
    if (i >= length) {
      return;
    }

    int left_index = get_left_child_index(i);
    int right_index = get_right_child_index(i);

    int smallest_index = i;
    if (left_index < length && data[left_index] < data[smallest_index]) {
      smallest_index = left_index;
    }

    if (right_index < length && data[right_index] < data[smallest_index]) {
      smallest_index = right_index;
    }

    if (smallest_index != i) {
      std::swap(data[i], data[smallest_index]);
      heapify_down(smallest_index);
    }
  }

  int get_parent_index(int i) { return floor((i - 1) / 2); }

  int get_left_child_index(int i) { return (2 * i) + 1; }

  int get_right_child_index(int i) { return (2 * i) + 2; }

public:
  int length;

private:
  std::vector<int> data;
};

#endif
