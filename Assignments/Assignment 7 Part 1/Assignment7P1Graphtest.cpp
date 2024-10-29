
#include <gtest/gtest.h>
#include "AdjList.hpp"
#include "AdjMatrix.hpp"

#include <iostream>

class GraphTest : public ::testing::Test
{
protected:
    AdjListGraph<int> testALG;
    AdjMatGraph<int> testAMG;
    void SetUp() override
    {
        testALG.addNode(0);
        testALG.addNode(1);
        testALG.addNode(2);
        testALG.addNode(3);

        testALG.addEdge(0, 1);
        testALG.addEdge(0, 2);
        testALG.addEdge(0, 3);

        testALG.addEdge(1, 0);
        testALG.addEdge(1, 2);
        testALG.addEdge(1, 3);

        testALG.addEdge(2, 0);
        testALG.addEdge(2, 1);
        testALG.addEdge(2, 3);

        testALG.addEdge(3, 0);
        testALG.addEdge(3, 1);
        testALG.addEdge(3, 2);

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

    void TearDown() override
    {
        // No tear down required.
    }
};

// Test: fill an adj list graph with data
// Precondition: Graph is empty
// Postcondition: Graph is filled per test
TEST_F(GraphTest, BuildAL)
{
    AdjListGraph<int>* g = new AdjListGraph<int>();
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

    EXPECT_TRUE(g->adjacent(2, 0));
    EXPECT_FALSE(g->adjacent(2, 1));
    delete g;
}

// Test: fill an adj list graph with data, treating as parent class
// Precondition: Graph is empty
// Postcondition: Graph is filled per test
TEST_F(GraphTest, BuildALAsParent)
{
    Graph<int>* g = new AdjListGraph<int>();
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

    EXPECT_TRUE(g->adjacent(2, 0));
    EXPECT_FALSE(g->adjacent(2, 1));
    delete g;
}

// Test: fill an adj list graph with data, treating as parent class
// Precondition: Graph is empty
// Postcondition: Graph is filled per test
TEST_F(GraphTest, BuildAM)
{
    AdjMatrixGraph<int>* g = new AdjMatrixGraph<int>();
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

    EXPECT_TRUE(g->adjacent(2, 0));
    EXPECT_FALSE(g->adjacent(2, 1));
    delete g;
}

// 
// Test: Get a list of neighbors out of a Graph
// Precondition: Graph is empty
// Postcondition: Graph is filled per test
TEST_F(GraphTest, NeighborsInAL)
{
    std::vector<int> expected = { 1, 2, 3 };
    std::vector<int> neighvec = testALG.neighbors(0);
    EXPECT_TRUE(neighvec == expected);
}

// 
// Test: Get a list of neighbors out of a Graph
// Precondition: Graph is contains a node 0 with neighbors 1,2,3
// Postcondition: The returned vector contains 1, 2, and 3
TEST_F(GraphTest, NeighborsInAM)
{
    std::vector<int> expected = { 1, 2, 3 };
    std::vector<int> neighvec = testAMG.neighbors(0);
    EXPECT_TRUE(neighvec == expected);
}

// Test: DFS traversal of a graph
// Precondition: Two graphs, an AdjList and AdjMatrix are available
// Postconition: Correct dfs generated for each graph.
TEST_F(GraphTest, DFS) {
    auto visit = [&](int n) { std::cout << n << " "; };
    std::cout << "DFS traversal:\n";
    testALG.dfs(0, visit);
    std::cout << "\n BFS traversal: \n";
    testAMG.dfs(0, visit);
}

// Test: BFS traversal of a graph
// Precondition: Two graphs, an AdjList and AdjMatrix are available
// Postconition: Correct bfs generated for each graph.
TEST_F(GraphTest, BFS) {
    auto visit = [&](int n) { std::cout << n << " "; };
    std::cout << "DFS traversal:\n";
    testALG.bfs(0, visit);
    std::cout << "\n BFS traversal: \n";
    testAMG.bfs(0, visit);
}