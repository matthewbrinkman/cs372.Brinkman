// This was created with the guidence of your code from GitHub
#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Graph.hpp"
using namespace std;
template <class N>
class AdjMatGraph : public Graph<N> {
private:
    class NodeEntry {
    public:
        N node;
        int index;
    };
    const static int maxSize = 10;
    bool adjMatrix[maxSize][maxSize];
    NodeEntry* nodes[maxSize];
    int numNodes = 0;
    int findMatrixNode(N x) {
        for (int j = 0; j < numNodes; ++j)
        {
            if (x == nodes[j]->node)
            {
                return j;
            }
        }
        return -1;
    }
public:
  
    AdjMatGraph()
    {
        for (int i = 0; i < maxSize; i++)
            for (int j = 0; j < maxSize; j++)
            {
                adjMatrix[i][j] = false;
            }
    }
   
    AdjMatGraph(vector<N> newNodes, vector<pair<N, N>> newEdges)
    {
        adjMatrix = new NodeEntry[maxSize][maxSize];
        for (typename vector<N>::const_iterator it = newNodes.begin();
            it < newNodes.end();
            ++it)
        {
            NodeEntry ne = new NodeEntry();
            ne.node = *it;
            ne.index = numNodes;
            nodes[numNodes] = ne;
        }
        for (typename vector<pair<N, N>>::const_iterator it = newEdges.begin();
            it < newEdges.end();
            ++it)
        {
            pair<N, N> edge = *it;
            int sourceIndex = findMatrixNode(edge.first);
            int destIndex = findMatrixNode(edge.second);
            if (sourceIndex != -1)
            {
                if (destIndex != -1)
                {
                    adjMatrix[sourceIndex][destIndex] = true;
                }
            }
        }
    }

    
    ~AdjMatGraph() {};

    virtual bool adj(N x, N y)
    {
        bool result = false;
        int xIndex = findMatrixNode(x);
        int yIndex = findMatrixNode(y);
        if ((xIndex != -1) && (yIndex != -1))
        {
            bool xy = adjMatrix[xIndex][yIndex];
            bool yx = adjMatrix[yIndex][xIndex];
            result = xy && yx;
        }
        return(result);
    }

    virtual vector<N> neighbors(N x)
    {
        vector<N>* v = new vector<N>();
        int xIndex = findMatrixNode(x);
        if (xIndex != -1)
        {
            for (int i = 0; i < numNodes; ++i) {
                if (adjMatrix[xIndex][i] == true) {
                    v->push_back(nodes[i]->node);
                }
            }
        }
        return *v;
    }
    virtual void addNode(N node)
    {
        NodeEntry* ne = new NodeEntry();
        ne->node = node;
        ne->index = numNodes;
        nodes[numNodes] = ne;
        numNodes++;

    }
    virtual void addEdge(N x, N y) {
        int xIndex = findMatrixNode(x);
        int yIndex = findMatrixNode(y);
        if ((xIndex != -1) && (yIndex != -1))
        {
            adjMatrix[xIndex][yIndex] = true;
        }
    }
    virtual void deleteEdge(N x, N y)
    {
        int xIndex = findMatrixNode(x);
        int yIndex = findMatrixNode(y);
        adjMatrix[xIndex][yIndex] = false;
    }

  
    void dfs(N startNode, function<void(N)> visit) {
        map<N, bool> visited;

        for (int i = 0; i < numNodes; ++i) {
            visited[nodes[i]->node] = false;
        }
        stack<N> s;
        s.push(startNode);
        while (!s.empty()) {
            N currentNode = s.top();
            s.pop();
            bool beenVisited = visited[currentNode];
            if (!beenVisited) {
                visit(currentNode);
                visited[currentNode] = true;
            }
            vector<N> neighVec = neighbors(currentNode);
            for (auto neighbor : neighVec) {
                if (!visited[neighbor]) { s.push(neighbor); }
            }
        }
    }

    void bfs(N startNode, function<void(N)> visit) {
        map<N, bool> visited;
        for (int i = 0; i < numNodes; ++i) {
            visited[nodes[i]->node] = false;
        }
        queue<N> q;
        q.push(startNode);
        while (!q.empty()) {
            N currentNode = q.front();
            q.pop();
            bool beenVisited = visited[currentNode];
            if (!beenVisited) {
                visit(currentNode);
                visited[currentNode] = true;
            }
            vector<N> neighVec = neighbors(currentNode);
            for (auto neighbor : neighVec) {
                if (!visited[neighbor]) { q.push(neighbor); }
            }
        }
    }
};
