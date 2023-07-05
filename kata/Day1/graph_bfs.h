#ifndef GRAPH_BFS
#define GRAPH_BFS

#include "graph.h"

#include <list>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

inline std::vector<std::string> bfs(Graph<std::string> &graph,
                                    const std::string &start_node) {
  std::vector<std::string> visited_nodes;
  std::queue<std::string> queue;
  std::unordered_set<std::string> visited_set;

  queue.push(start_node);
  visited_set.insert(start_node);

  while (!queue.empty()) {
    std::string current_node = queue.front();
    queue.pop();
    visited_nodes.push_back(current_node);

    for (const auto &neighbour : graph.get_neighbours(current_node)) {
      if (visited_set.find(neighbour) == visited_set.end()) {
        queue.push(neighbour);
        visited_set.insert(neighbour);
      }
    }
  }

  return visited_nodes;
}

#endif
