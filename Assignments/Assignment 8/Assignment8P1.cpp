// created with the help of claude.ai

#include <gtest/gtest.h>
#include "Adjmatrixgraph.hpp"
#include <iostream>
#include <vector>

class GraphTest : public ::testing::Test {
protected:
    AdjMatGraph<int> testAMG;

    void SetUp() override {
        // Initialize the adjacency matrix graph
        testAMG.addNode(0);
        testAMG.addNode(1);
        testAMG.addNode(2);
        testAMG.addNode(3);

        testAMG.addEdge(0, 1);
        testAMG.addEdge(0, 2);
        testAMG.addEdge(0, 3);
        testAMG.addEdge(1, 0);
        testAMG.addEdge(1, 2);
        testAMG.addEdge(1, 3);
        testAMG.addEdge(2, 0);
        testAMG.addEdge(2, 1);
        testAMG.addEdge(2, 3);
        testAMG.addEdge(3, 0);
        testAMG.addEdge(3, 1);
        testAMG.addEdge(3, 2);
    }

    void TearDown() override {
        // No tear down required since we're using stack allocation
    }
};

// Test building and basic operations of adjacency matrix graph
TEST_F(GraphTest, BuildAM) {
    AdjMatGraph<int>* g = new AdjMatGraph<int>();

    g->addNode(0);
    g->addNode(1);
    g->addNode(2);
    g->addNode(3);

    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(0, 3);
    g->addEdge(1, 0);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(2, 0);
    g->addEdge(2, 1);
    g->addEdge(2, 3);
    g->addEdge(3, 0);
    g->addEdge(3, 1);
    g->addEdge(3, 2);

    g->deleteEdge(2, 1);

    // Test adjacency after edge deletion
    EXPECT_TRUE(g->adj(2, 0));  // Changed adjacent to adj to match your class
    EXPECT_FALSE(g->adj(2, 1));

    delete g;
}

// Test neighbors function for adjacency matrix
TEST_F(GraphTest, NeighborsInAM) {
    std::vector<int> expected = { 1, 2, 3 };
    std::vector<int> neighvec = testAMG.neighbors(0);
    EXPECT_EQ(neighvec, expected);  // Changed to EXPECT_EQ for better error messages
}

// Test DFS traversal
TEST_F(GraphTest, DFS) {
    std::cout << "DFS traversal:\n";
    auto visit = [](int n) { std::cout << n << " "; };
    testAMG.dfs(0, visit);
    std::cout << std::endl;
}

// Test BFS traversal
TEST_F(GraphTest, BFS) {
    std::cout << "BFS traversal:\n";
    auto visit = [](int n) { std::cout << n << " "; };
    testAMG.bfs(0, visit);
    std::cout << std::endl;
}

// Optional: Main function if you're not using gtest's main
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}