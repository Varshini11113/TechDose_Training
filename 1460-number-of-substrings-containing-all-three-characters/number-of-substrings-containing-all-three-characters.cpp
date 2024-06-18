class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int>mp;
        int count = 0;
        int l = 0, r = 0, n = s.length();
        while(r < n){
            mp[s[r]]++;
            while(mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1){
                count += (n - r);
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return count;
    }
};