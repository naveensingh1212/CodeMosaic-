#include <vector>
#include <deque>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> l; // stores indexes or values of negative numbers
        int n = arr.size();
        int i = 0, j = 0;

        while (j < n) {
            // Step 1: Store negative number
            if (arr[j] < 0) {
                l.push_back(arr[j]);
            }

            // Step 2: If window size is less than k, move j
            if (j - i + 1 < k) {
                j++;
            }

            // Step 3: If window size is k
            else if (j - i + 1 == k) {
                if (!l.empty()) {
                    ans.push_back(l.front());
                    if (arr[i] == l.front()) {
                        l.pop_front(); // Remove if going out of window
                    }
                } else {
                    ans.push_back(0);
                }
                i++;
                j++;
            }
        }

        return ans;
    }
};
