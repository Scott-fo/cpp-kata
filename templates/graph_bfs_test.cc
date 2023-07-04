#include "graph_bfs.h"

#include <gtest/gtest.h>

TEST(GraphTest, BFS) {
  Graph<std::string> g;
  g.add_edge("A", "B");
  g.add_edge("A", "C");
  g.add_edge("B", "D");
  g.add_edge("C", "D");
  g.add_edge("C", "E");
  g.add_edge("E", "F");

  auto bfsResult = bfs(g, "A");

  std::vector<std::string> expected = {"A", "B", "C", "D", "E", "F"};
  EXPECT_EQ(bfsResult, expected);
}
