#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool detectCycle(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto adjacentNode : adj[node]) {  // ✅ Correct adjacency access
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } 
                else if (parent != adjacentNode) {
                    return true; // Cycle detected
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);  
        }

        
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detectCycle(i, adj, vis)) return true;
            }
        }
        return false;
    }
};
