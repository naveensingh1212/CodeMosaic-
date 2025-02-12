#include <iostream>
#include <vector>
using namespace std;

/*
    Kadane’s Algorithm:
    - Used to find the maximum sum subarray in O(n) time complexity.
    - It works by maintaining:
      1. `curr`: Maximum sum ending at the current index.
      2. `max_so_far`: The maximum sum encountered so far.
    - At each step, we check whether to:
      - Extend the current subarray by adding `nums[i]` to `curr`
      - Start a new subarray from `nums[i]`
*/

int kadaneAlgorithm(vector<int>& nums) {
    int max_so_far = nums[0];  // Stores the maximum sum found so far
    int curr = nums[0];        // Stores the maximum sum ending at the current index

    for (int i = 1; i < nums.size(); i++) {
        // Either start a new subarray from nums[i] or extend the previous one
        curr = max(nums[i], curr + nums[i]);

        // Update the maximum subarray sum found so far
        max_so_far = max(max_so_far, curr);
    }

    return max_so_far;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return kadaneAlgorithm(nums);
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << kadaneAlgorithm(nums) << endl;
    return 0;
}
