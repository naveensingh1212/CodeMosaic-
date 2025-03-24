#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjacencyList; // Global adjacency list

// Recursive DFS function
void DFSrecursive(int vertex, unordered_set<int>& visited) {
    cout << vertex << " ";  // Process the node
    visited.insert(vertex); // Mark as visited

    for (int neighbor : adjacencyList[vertex]) {
        if (visited.find(neighbor) == visited.end()) {  // If not visited
            DFSrecursive(neighbor, visited);
        }
    }
}

// Wrapper function for recursive DFS
void dfs(int startVertex) {
    unordered_set<int> visited;
    cout << "DFS Recursive Traversal: ";
    DFSrecursive(startVertex, visited);
    cout << endl;
}

// Iterative DFS using stack
void dfsIterative(int startVertex) {
    unordered_set<int> visited;
    stack<int> st;
    st.push(startVertex);

    while (!st.empty()) {
        int currentVertex = st.top();
        st.pop();

        if (visited.find(currentVertex) == visited.end()) {
            cout << currentVertex << " "; // Process the node
            visited.insert(currentVertex);

            // Push unvisited neighbors (in reverse order for correct order)
            for (auto it = adjacencyList[currentVertex].rbegin(); it != adjacencyList[currentVertex].rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    st.push(*it);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    // Define the graph
    adjacencyList = {
        {0, {1, 2}},
        {1, {0, 3, 4}},
        {2, {0, 5, 6}},
        {3, {1}},
        {4, {1}},
        {5, {2}},
        {6, {2}}
    };

    cout << "DFS Iterative Traversal: ";
    dfsIterative(0); // Call iterative DFS

    dfs(0); // Call recursive DFS

    return 0;
}




/*

const int N = 1e5;
vector<vector<int>> adjacencyList(N);

void addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}


const int N = 1e5;
vector<vector<int>> adjacencyList(N);

void addEdge(int u, int v) {
    adjacencyList[u].push_back(v); // Only u → v
}


*/