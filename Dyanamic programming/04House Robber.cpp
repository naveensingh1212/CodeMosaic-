// //Memoization
class Solution {
    private:
    int f(int ind , vector<int>&dp,vector<int>& nums){
        if(ind ==0 ) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick =nums[ind] + f(ind-2,dp,nums);
        int Npick =0+f(ind-1,dp,nums); 
        return dp[ind] = max(pick,Npick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int res = f(n-1,dp,nums);
    return res;
    }
};

//Tabulation
class Solution1 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};
