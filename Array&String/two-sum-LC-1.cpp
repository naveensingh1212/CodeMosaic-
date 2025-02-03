#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> res_set; 
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) { 
                if (nums[i] + nums[j] == target) {
                    res_set.insert(i);
                    res_set.insert(j);
                    break;  
                }
            }
        }

        vector<int> temp;
        for (int elem : res_set) {
            temp.push_back(elem);
        }

        return temp;
    }

    vector<int> twoSumsol(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};  
                }
            }
        }
        return {};  
    }

    vector<int> twoSumopti(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i]; 
            
            if (mp.find(rem) != mp.end()) {
                return {mp[rem], i};  
            }
            
            mp[nums[i]] = i;  
        }
        
        return {};  
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result1 = sol.twoSum(nums, target);
    cout << "twoSum: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result2 = sol.twoSumsol(nums, target);
    cout << "twoSumsol: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result3 = sol.twoSumopti(nums, target);
    cout << "twoSumopti: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
