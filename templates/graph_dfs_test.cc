#include "graph_dfs.h"
#include <gtest/gtest.h>

TEST(GraphTest, DFS) {
  Graph<std::string> g;
  g.addEdge("A", "B");
  g.addEdge("A", "C");
  g.addEdge("B", "D");
  g.addEdge("C", "D");
  g.addEdge("C", "E");
  g.addEdge("E", "F");

  auto dfsResult = dfs(g, "A");

  std::vector<std::string> expected = {"A", "C", "E", "F", "D", "B"};
  EXPECT_EQ(dfsResult, expected);
}
