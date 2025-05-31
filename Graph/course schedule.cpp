class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> indegree(numCourses, 0);
            vector<vector<int>> adj(numCourses);
    
            for (auto& edge : prerequisites) {
                int u = edge[1];
                int v = edge[0];
                adj[u].push_back(v);
                indegree[v]++;
            }
    
            queue<int> q;
            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
    
            int count = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                count++;
    
                for (auto neighbor : adj[node]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
    
            // If we were able to process all courses, return true
            return count == numCourses;
        }
    };
// The code implements a solution to the "Course Schedule" problem using Kahn's algorithm for topological sorting.    