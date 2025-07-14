class Solution {
private:
    void dfs(vector<int>& edges, int node, vector<int>& dist, vector<bool>& visited) {
        int distance = 0;
        while (node != -1 && !visited[node]) {
            dist[node] = distance++;
            visited[node] = true;
            node = edges[node];
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        dfs(edges, node1, dist1, visited1);
        dfs(edges, node2, dist2, visited2);

        int minDistNode = -1;
        int minDistTillNow = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDistTillNow) {
                    minDistTillNow = maxDist;
                    minDistNode = i;
                }
            }
        }

        return minDistNode;
    }
};
 zS 