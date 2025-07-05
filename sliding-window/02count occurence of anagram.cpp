class Solution {
  public:
    int search(string pat, string txt) {
        vector<int> patHash(26, 0);
        vector<int> winHash(26, 0);
        int patLen = pat.size();
        int txtLen = txt.size();

        if (patLen > txtLen) return 0;

        // Count frequency of each character in pattern
        for (int i = 0; i < patLen; i++) {
            patHash[pat[i] - 'a']++;
            winHash[txt[i] - 'a']++;
        }

        int count = 0;

        // Check for first window
        if (patHash == winHash) count++;

        // Slide the window
        for (int i = patLen; i < txtLen; i++) {
            winHash[txt[i] - 'a']++;                     // add new char
            winHash[txt[i - patLen] - 'a']--;            // remove old char

            if (winHash == patHash) count++;             // compare arrays
        }

        return count;
    }
};



///USING WHILE LOOP
class Solution {
  public:
    int search(string pat, string txt) {
        vector<int> patHash(26, 0); // frequency of characters in pat
        vector<int> winHash(26, 0); // frequency of current window in txt
        
        int k = pat.size(); // size of the window
        int n = txt.size(); // total size of the text

        if (k > n) return 0;

        // build the frequency map for pattern
        for (int i = 0; i < k; i++) {
            patHash[pat[i] - 'a']++;
        }

        int i = 0, j = 0, count = 0;

        while (j < n) {
            // include current character in window hash
            winHash[txt[j] - 'a']++;

            // if window size < k, just expand
            if (j - i + 1 < k) {
                j++;
            }

            // when window size == k, process it
            else if (j - i + 1 == k) {
                // compare pattern hash with current window hash
                if (winHash == patHash) count++;

                // slide the window: remove txt[i] from winHash
                winHash[txt[i] - 'a']--;
                i++;
                j++;
            }
        }

        return count;
    }
};


