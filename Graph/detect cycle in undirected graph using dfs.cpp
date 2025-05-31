class Solution {
    private: 
        bool dfs(int node, int parent, vector<vector<int>>& adjLs, vector<int>& vis) {
            vis[node] = 1;
            for (auto it : adjLs[node]) {
                if (!vis[it]) {
                    if (dfs(it, node, adjLs, vis)) {
                        return true;
                    }
                }
                else if (it != parent) {
                    return true;
                }
            }
            return false;
        }
    
    public:
        bool isCycle(int V, vector<vector<int>>& edges) {
            vector<vector<int>> adjLs(V);
            vector<int> vis(V, 0);
    
            // Build adjacency list
            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adjLs[u].push_back(v);
                adjLs[v].push_back(u);
            }
    
            // Check for cycle in all components
            for (int i = 0; i < V; i++) {
                if (!vis[i]) {
                    if (dfs(i, -1, adjLs, vis)) {
                        return true;
                    }
                }
            }
    
            return false;
        }
    };
    