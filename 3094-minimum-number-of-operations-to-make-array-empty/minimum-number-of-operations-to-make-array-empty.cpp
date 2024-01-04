class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int>mp;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto i : mp){
            if(i.second < 2) return -1;
            else{
                ans += (i.second+2)/3;
            }
        }
        return ans;
    }
};