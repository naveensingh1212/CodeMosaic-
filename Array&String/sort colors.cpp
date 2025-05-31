
// 75. Sort Colors
// DUTCH NATIONAL FLAG PROBLEM


class Solution {
    public:
        void sortColors(vector<int>& nums) {
    
            int low = 0, mid = 0, high = nums.size()-1;
            while(mid <= high){
                if(nums[mid] == 0){
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                }
                else if(nums[mid] == 1){
                    mid++;
                }
                else{
                    swap(nums[mid], nums[high]);
                    high--;
                }
            }
        }
    };




    
            /*
The idea behind the algorithm is to keep all the 0s before the low pointer, all the 2s after the high pointer, and all the 1s between the low and high pointers.
The algorithm moves the mid pointer through the array, comparing the value at each position with 1. 
If the value is 0, the element is swapped with the element at the low pointer, and the low and mid pointers are incremented. 
If the value is 2, the element is swapped with the element at the high pointer, and the high pointer is decremented.
If the value is 1, the mid pointer is simply incremented.
 The algorithm terminates when the mid pointer crosses the high pointer, indicating that all the elements have been processed and the array is sorted.
The Dutch National Flag algorithm is called one-pass because it sorts the array in a single pass through the elements. The time complexity of the algorithm is O(n), where n is the size of the array.
    
            */