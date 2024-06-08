class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int>mp;
        for(int x : nums){
            ans += mp[x]++;
        }
        return ans;
    }
};