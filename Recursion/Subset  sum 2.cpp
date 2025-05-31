class Solution {
    private:
        void sub(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
            ans.push_back(ds);
            for (int i = ind; i < nums.size(); ++i) {
                if (i > ind && nums[i] == nums[i - 1]) continue; // Skip duplicates
                ds.push_back(nums[i]);
                sub(i + 1, nums, ans, ds);
                ds.pop_back();
            }
        }
    
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> ds;
            sort(nums.begin(), nums.end()); // Sort to handle duplicates
            sub(0, nums, ans, ds);
            return ans;
        }
    };
    