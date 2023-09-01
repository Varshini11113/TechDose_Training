class Solution {
public:
    vector<int> countBits(int n) {
        //set bits even -> setbit 
        //odd = 1 + setbit
        vector<int>ans(n+1);
        ans[0] = 0;
        for(int i = 1; i<=n; i++){
            ans[i] = (ans[i/2] + i % 2);
            // else ans[i] = ans[i/2];
        }
        return ans;
    }
};