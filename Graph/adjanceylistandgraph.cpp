#include <iostream>
#include <vector>
using namespace std;

// Graph representation using an adjacency matrix
int main() {
    int n, m;
    cin >> n >> m; // n = number of vertices, m = number of edges

    int adj[n+1][n+1] = {0}; // Initialize matrix with 0s

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected Graph (Edge from u to v and v to u)
        adj[u][v] = 1;
        adj[v][u] = 1;

        // For a Directed Graph, only do:
        // adj[u][v] = 1;
    }

    return 0;
}

// Graph representation using an adjacency list
void adjacencyList() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // Using vector of vectors

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected Graph
        adj[u].push_back(v);
        adj[v].push_back(u);

        // For a Directed Graph, only do:
        // adj[u].push_back(v);

        /*
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        */
    }
}
