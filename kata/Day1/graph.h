#ifndef GRAPH_H
#define GRAPH_H

#include <stdexcept>
#include <unordered_map>
#include <vector>

template <typename T> class Graph {
public:
  Graph() {}

  void add_edge(const T &a, const T &b) {
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  const std::vector<T> &get_neighbours(const T &node) const {
    auto iterator = adj_list.find(node);
    if (iterator == adj_list.end()) {
      throw std::out_of_range("Node not found");
    }

    return iterator->second;
  }

private:
  std::unordered_map<T, std::vector<T>> adj_list;
};

#endif
