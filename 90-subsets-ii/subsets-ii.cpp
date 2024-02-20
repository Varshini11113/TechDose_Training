class Solution {
public:
    void subset(vector<int>&nums, vector<vector<int>>&ans, vector<int>&res, int ind){
        ans.push_back(res);
        for(int i = ind; i<nums.size(); i++){
            if(i != ind && nums[i] == nums[i-1]){
                continue;
            }
            res.push_back(nums[i]);
            subset(nums, ans, res, i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(), nums.end());
        subset(nums, ans, res, 0);
        return ans;
    }
};