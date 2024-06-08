class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>mp(26,0);
        int l = 0, r = 0, maxF = 0, maxL = 0;
        while(r < n){
            mp[s[r] - 'A']++;
            maxF = max(maxF, mp[s[r] - 'A']);
            r++;
            if(r - l - maxF > k){
                mp[s[l] - 'A']--;
                l++;
            }
        }
        maxL = r - l;
        return maxL;
    }
};