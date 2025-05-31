class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int>ans(n+1);
            for(int i =0;i<=n;i++)
            {
                ans[i] = onesInNum(i);
            }
            return ans;
        }
    
        private:
        int onesInNum(int num){
            int ones = 0;
            while(num>0){
                if((num & 1)== 1) ones++;
                num = num >> 1;
            }
            return ones;
        }
    };