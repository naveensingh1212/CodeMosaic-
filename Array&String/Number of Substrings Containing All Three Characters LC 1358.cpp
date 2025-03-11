class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = size(s);
    
            int i=0,j=0,count=0;
    
            unordered_map<char, int> mp;
    
            while(j<n)
            {
                mp[s[j]]++;
    
                while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
                {
                    count += (n - j);
    
                    //shrinking the window
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
    
    
    
            return count;
        }
    
    //O(N^2)
        int numberOfSubstrings2(string s) {
            int n = s.size();
            int count =0;
            for(int i=0; i<n; i++){
                unordered_map<int , int > mpp;
                for(int j=i; j<n; j++){
                    mpp[s[j] - 'a'] = 1;
                    if(mpp[0] + mpp[1] + mpp[2] == 3){
                        count+= n-j;
                        break;
                    }
                }
            }
            return count;
        }
    };