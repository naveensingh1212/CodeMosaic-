class Solution {
    public:
      // Function to find the shortest path from source to all other nodes
      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
          
          int n = adj.size();
         vector<vector<int>>adjLs(n);
          for(auto edge : adj){
              adjLs[edge[0]].push_back(edge[1]);
              adjLs[edge[1]].push_back(edge[0]);
              
          }
          
          vector<int>dist(n,1e9);
          queue<int>q;
          dist[src] = 0;
          q.push(src);
          
          while(!q.empty()){
              int node = q.front();
              q.pop();
              
              for(auto it : adjLs[node]){
                  if(dist[node]+1 < dist[it]){
                      dist[it] = 1+ dist[node];
                      q.push(it);
                  }
              }
          }
          
          vector<int>ans(n,-1);
          for(int i=0; i<n;i++){
              if(dist[i] != 1e9){
                  ans[i] = dist[i];
              }
          }
          return ans ;
      }
  };
  