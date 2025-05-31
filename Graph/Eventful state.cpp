class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int V = graph.size();
               vector<int> indegree(V, 0);
            vector<vector<int>> adjRev(V);
    
            for(int i =0; i<V ; i++){
                for(auto it : graph[i]){
                    adjRev[it].push_back(i);
                    indegree[i]++;
                }
            }
        vector<int>safenode;
            queue<int>q;
            for(int i=0;i<V ;i++){
                if(indegree[i] == 0){
                q.push(i);
                }
            }
    
            while(!q.empty()){
                int node = q.front();
                q.pop();
                safenode.push_back(node);
                for(auto it : adjRev[node]){
                    indegree[it]--;
                    if(indegree[it] == 0){
                        q.push(it);
    
                    }
                }
            }
            sort(safenode.begin(),safenode.end());
            return safenode;
        }
    };