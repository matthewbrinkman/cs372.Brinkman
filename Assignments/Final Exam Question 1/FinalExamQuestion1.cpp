// This code is made with the help of claude.ai and the tree class from GitHub. The prompt is the question along with the tree class.
#include "FinalExamQ1.hpp"
#include <iostream>

int main() {
    Tree<int> tree = { {5, 3, 7, 1, 4, 6, 8} };
    
    int totalNodes = countNodes(tree);
    std::cout << "Total nodes: " << totalNodes << std::endl;

    int internalNodes = countInternalNodes(tree);
    std::cout << "Internal nodes: " << internalNodes << std::endl;

    int pathLength = 0;
    externalPathLength(tree, pathLength);
    std::cout << "External path length: " << pathLength << std::endl;

    return 0;
}
