#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template <typename T> class Graph {
public:
  Graph() {}

  void addEdge(const T &a, const T &b) {}

  const std::vector<T> &getNeighbors(const T &node) const {}
};

#endif
