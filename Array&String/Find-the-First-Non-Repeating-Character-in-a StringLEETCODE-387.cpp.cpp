#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
// optimized
 int firstUniqChar(string s) {
        unordered_map<char, int> mpp;

        // Count occurrences of each character
        for (char ch : s) {
            mpp[ch]++;
        }

        // Find the first character with count 1
        for (int i = 0; i < s.size(); i++) {
            if (mpp[s[i]] == 1) {
                return i;
            }
        }
        return -1;
 }


//optim
 int firstUniqueChar(string s) {

        vector<int> freq(26, 0);

        for (int i = s.size() - 1; i >= 0; i--) {
            freq[s[i]-'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }

// TLE
      int firsstUniqChar(string s) {
      
        for(int i =0 ;i < s.size(); i++){
            int cnt=0;
            for(int j=0;j<s.size();j++){
                if(s[i] == s[j]){
                    cnt++;
                }
            }
        if(cnt == 1){
            return i;
            break;
        }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string s = "leetcode";

    cout << "Optimized approach: " << sol.firstUniqChar(s) << endl;
    cout << "Optimized (vector) approach: " << sol.firstUniqueChar(s) << endl;
    cout << "TLE approach: " << sol.firsstUniqChar(s) << endl;

    return 0;
}
