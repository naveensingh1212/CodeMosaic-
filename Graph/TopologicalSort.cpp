class Solution {
    void dfs(int node, vector<int> &vis, stack<int> &s, vector<vector<int>> &adj) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, s, adj);
            }
        }

        s.push(node);
    }

  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]); 
        }

        vector<int> vis(V, 0);
        stack<int> s;

        // Step 2: Perform DFS from each unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, s, adj);
            }
        }

        // Step 3: Pop from stack to get topological order
        vector<int> topo;
        while (!s.empty()) {
            topo.push_back(s.top());
            s.pop();
        }

        return topo;
    }
};