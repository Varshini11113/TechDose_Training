class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(128,0);
        int l = 0, r = 0, maxF = 0;
        while(r < s.size()){
            freq[s[r]]++;
            maxF = max(maxF, freq[s[r]]);
            r++;
            // if((r-l+1) - maxF <= k){
            //     maxL = max(maxL, r-l+1);
            // }
            if(r - l - maxF > k){
                freq[s[l]]--;
                l++;
            }
        }
        return r - l;
    }
};