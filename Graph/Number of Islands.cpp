class Solution {
    void dfs(int i,int j,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>= grid.size() || j<0 || j>= grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';

        dfs(i,j-1,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);

        }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int cnt=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0 ; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                dfs(i,j,grid);
                cnt++;
                }
            }
        }
        return cnt;
    }
};