class Solution {
    public:
        void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
            vis[node] = 1;
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    dfs(it, adj, vis);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int num = 0;
            int n = isConnected.size();
            int m = isConnected[0].size();
            vector<vector<int>> adj(n);
            vector<int> vis(n, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (isConnected[i][j] && i != j) {
                        adj[i].push_back(j);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    dfs(i, adj, vis);
                    num++;
                }
            }
            return num;
        }
    };