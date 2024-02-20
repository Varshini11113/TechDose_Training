class Solution {
public:
    void sub(vector<int>&nums, vector<vector<int>> &ans, vector<int>&ds, int ind, int n){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        sub(nums, ans, ds, ind+1, n);
        ds.pop_back();
        sub(nums, ans, ds, ind+1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        sub(nums, ans, ds, 0, n);
        return ans;
    }
};