class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>mp;
        vector<int>res;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};