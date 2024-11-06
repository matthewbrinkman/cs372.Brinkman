#pragma once
// This was created with the guidence of your code from GitHub

#include <vector>
#include <utility>
#include <functional>
using namespace std;

template <class N>
class Graph {
public:
    Graph() {};
    Graph(vector<N> nodes, vector<pair<N, N>> edges) {};
    virtual ~Graph() {};

    virtual bool adjacent(N x, N y) = 0;
    virtual vector<N> neighbors(N x) = 0;
    virtual void addNode(N x) = 0;
    virtual void addEdge(N x, N y) = 0;
    virtual void deleteEdge(N x, N y) = 0;

    virtual void dfs(N startNode, function<void(N)> visit) = 0;
    virtual void bfs(N startNode, function<void(N)> visit) = 0;
};
