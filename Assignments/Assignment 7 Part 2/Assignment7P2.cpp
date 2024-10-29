// This was created with the help of claude.ai

#include <iostream>
#include "socialgraph.hpp"
#include <vector>
using namespace std;

int main() {
    SocialGraph graph;
    vector<string> path;

    cout << "Social Graph Structure:" << endl;
    graph.printGraph();

    bool connected = graph.findPathToKevinBacon(path);

    if (connected) {
        cout << "\nPath to Kevin Bacon found!" << endl;
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << "\nDegrees of separation: " << path.size() - 1 << endl;
    }
    else {
        cout << "\nNo path to Kevin Bacon found!" << endl;
    }

    return 0;
}