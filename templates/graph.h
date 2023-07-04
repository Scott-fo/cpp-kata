#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template <typename T> class Graph {
public:
  Graph() {}

  void add_edge(const T &a, const T &b) {}

  const std::vector<T> &get_neighbours(const T &node) const {}
};

#endif
