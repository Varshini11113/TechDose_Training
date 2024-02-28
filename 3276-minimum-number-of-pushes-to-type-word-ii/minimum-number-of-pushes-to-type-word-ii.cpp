class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(auto i : word){
            mp[i - 'a']++;
        }
        int ans = 0;
        sort(mp.begin(), mp.end(), greater<int>());
        for(int i = 0; i<mp.size(); i++){
            ans += mp[i] * ((i/8) + 1);
        }
        return ans;
    }
};