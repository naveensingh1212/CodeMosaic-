class Solution {
    private:
     bool checkBipartite(int node,vector<int>&temp,vector<vector<int>>& graph) {
        temp[node] =0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it :graph[node]){
                //if adjacent node is not coloured give it opp col
                if(temp[it] == -1){
                    temp[it] = !temp[node];
                    q.push(it);
                }
                else if(temp[it] == temp[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
        vector<int>temp(n,-1);
        //for multicomponent
        for(int i=0;i<n;i++){
            if(temp[i] == -1 ){
                if(checkBipartite(i,temp,graph) == false ){
                    return false ;
                }
            }
        }
        return true;
    }
};