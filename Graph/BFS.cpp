#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjacencyList;

void bfsIterative(int startVertex) {
    unordered_set<int> visited;
    queue<int> q;

    q.push(startVertex);  // Push the start node
    visited.insert(startVertex);  // Mark as visited

    while (!q.empty()) {
        int currentVertex = q.front(); // Get front element
        q.pop(); // Remove from queue

        cout << currentVertex << " ";  // Process the node

        // Traverse neighbors
        for (int neighbor : adjacencyList[currentVertex]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);  // Mark as visited when adding to queue
            }
        }
    }
}

void addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u); // Remove this line for a directed graph
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);

    cout << "BFS Traversal: ";
    bfsIterative(0);

    return 0;
}
