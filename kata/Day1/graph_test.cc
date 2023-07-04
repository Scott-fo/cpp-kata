#include "graph.h"

#include <gtest/gtest.h>
#include <string>

TEST(GraphTest, AddAndGetNeighbors) {
  Graph<std::string> g;
  g.add_edge("A", "B");
  g.add_edge("A", "C");
  g.add_edge("B", "D");

  auto aNeighbors = g.get_neighbours("A");
  auto bNeighbors = g.get_neighbours("B");
  auto cNeighbors = g.get_neighbours("C");
  auto dNeighbors = g.get_neighbours("D");

  // Ensure that A is connected to B and C
  ASSERT_EQ(aNeighbors.size(), 2);
  EXPECT_EQ(aNeighbors[0], "B");
  EXPECT_EQ(aNeighbors[1], "C");

  // Ensure that B is connected to A and D
  ASSERT_EQ(bNeighbors.size(), 2);
  EXPECT_EQ(bNeighbors[0], "A");
  EXPECT_EQ(bNeighbors[1], "D");

  // Ensure that C is connected to A
  ASSERT_EQ(cNeighbors.size(), 1);
  EXPECT_EQ(cNeighbors[0], "A");

  // Ensure that D is connected to B
  ASSERT_EQ(dNeighbors.size(), 1);
  EXPECT_EQ(dNeighbors[0], "B");
}
