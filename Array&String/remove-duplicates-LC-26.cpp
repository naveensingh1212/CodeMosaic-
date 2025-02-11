class Solution {
public:
//set
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end()); // Insert all elements into a set
        nums.assign(s.begin(), s.end()); // Copy unique elements back to nums
        return nums.size();
    }


//two pointer
    int removeDuplicateeee(vector<int>&nums){
        int i =0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
