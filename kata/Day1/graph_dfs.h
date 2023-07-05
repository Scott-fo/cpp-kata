#ifndef GRAPH_DFS_H
#define GRAPH_DFS_H

#include "graph.h"

#include <string>
#include <unordered_set>
#include <vector>

inline void dfs_util(Graph<std::string> &graph, const std::string &node,
                     std::unordered_set<std::string> &visited,
                     std::vector<std::string> &result) {
  visited.insert(node);

  result.push_back(node);

  for (const auto &adj : graph.get_neighbours(node)) {
    if (visited.find(adj) == visited.end()) {
      dfs_util(graph, adj, visited, result);
    }
  }
}

inline std::vector<std::string> dfs(Graph<std::string> &graph,
                                    const std::string &start_node) {
  std::vector<std::string> result;
  std::unordered_set<std::string> visited;

  dfs_util(graph, start_node, visited, result);

  return result;
}

#endif
