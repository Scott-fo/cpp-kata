#include "graph_dfs.h"
#include <gtest/gtest.h>

TEST(GraphTest, DFS) {
  Graph<std::string> g;
  g.add_edge("A", "B");
  g.add_edge("A", "C");
  g.add_edge("B", "D");
  g.add_edge("C", "D");
  g.add_edge("C", "E");
  g.add_edge("E", "F");

  auto dfsResult = dfs(g, "A");

  std::vector<std::string> expected = {"A", "C", "E", "F", "D", "B"};
  EXPECT_EQ(dfsResult, expected);
}
