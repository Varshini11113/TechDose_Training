class Solution {
public:
    void findsubsets(vector<int>&nums, int i, vector<vector<int>>&ans, vector<int>&ds){
        int n = nums.size();
        if(i == n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        findsubsets(nums, i+1, ans, ds);
        ds.pop_back();
        findsubsets(nums, i+1, ans, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>ds;
       findsubsets(nums, 0, ans, ds);
       return ans; 
    }
};