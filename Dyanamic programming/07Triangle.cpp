//MEmoization
class Solution {
    private:
    int minsum (int i, int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        int n = triangle.size();
        
        if(i==n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int d = triangle[i][j]+ minsum(i+1,j,triangle,dp);
        int di = triangle[i][j]+ minsum(i+1,j+1,triangle,dp);
         dp[i][j]= min(d, di);
        return dp[i][j];

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return minsum(0,0,triangle,dp);
    }
};