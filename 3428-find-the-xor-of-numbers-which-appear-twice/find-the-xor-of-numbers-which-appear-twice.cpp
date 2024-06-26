class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2){
                ans ^= nums[i];
            }
        }
        return ans;
    }
};