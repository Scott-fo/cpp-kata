#include "graph_bfs.h"

#include <gtest/gtest.h>

TEST(GraphTest, BFS) {
  Graph<std::string> g;
  g.addEdge("A", "B");
  g.addEdge("A", "C");
  g.addEdge("B", "D");
  g.addEdge("C", "D");
  g.addEdge("C", "E");
  g.addEdge("E", "F");

  auto bfsResult = bfs(g, "A");

  std::vector<std::string> expected = {"A", "B", "C", "D", "E", "F"};
  EXPECT_EQ(bfsResult, expected);
}
