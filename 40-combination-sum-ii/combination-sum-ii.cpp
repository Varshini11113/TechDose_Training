class Solution {
public:
    void combination(vector<vector<int>>&ans, vector<int>&ds, vector<int>&nums, int ind, int target){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            ds.push_back(nums[i]);
            combination(ans, ds, nums, i+1, target-nums[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        combination(ans, ds, nums, 0, target);
        return ans;
    }
};