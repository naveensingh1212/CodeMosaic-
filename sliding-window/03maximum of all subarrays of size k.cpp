class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> res;
        deque<int> dq;
        int i = 0, j = 0;

        while (j < n) {
            //calculation
            // Remove smaller elements from the back of deque
            while (!dq.empty() && dq.back() < arr[j]) {
                dq.pop_back();
            }

            dq.push_back(arr[j]);

            // If window size < k, just move j
            if (j - i + 1 < k) {
                j++;
            }
            // When window size == k
            //ans <- calculation
            else if (j - i + 1 == k) {
                res.push_back(dq.front());  // Front is max of window

                // Remove the element going out of the window
                if (arr[i] == dq.front()) {
                    dq.pop_front();
                }

                // Slide the window
                i++;
                j++;
            }
        }

        return res;
    }
};


// For looop
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> res;
        deque<int> dq;
        int i = 0, j = 0;

        while (j < n) {
            // Remove smaller elements from the back of deque
            while (!dq.empty() && dq.back() < arr[j]) {
                dq.pop_back();
            }

            dq.push_back(arr[j]);

            // If window size < k, just move j
            if (j - i + 1 < k) {
                j++;
            }
            // When window size == k
            else if (j - i + 1 == k) {
                res.push_back(dq.front());  // Front is max of window

                // Remove the element going out of the window
                if (arr[i] == dq.front()) {
                    dq.pop_front();
                }

                // Slide the window
                i++;
                j++;
            }
        }

        return res;
    }
};
