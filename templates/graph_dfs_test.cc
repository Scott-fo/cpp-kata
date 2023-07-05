#include "graph_dfs.h"
#include <gtest/gtest.h>

TEST(GraphTest, DFS) {
  Graph<std::string> g;
  g.add_edge("A", "B");
  g.add_edge("B", "C");
  g.add_edge("C", "D");
  g.add_edge("D", "E");
  g.add_edge("E", "F");

  auto dfsResult = dfs(g, "A");

  std::vector<std::string> expected = {"A", "B", "C", "D", "E", "F"};
  EXPECT_EQ(dfsResult, expected);
}
