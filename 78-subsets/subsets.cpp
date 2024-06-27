class Solution {
public:
    void subsequence(int i, vector<int>&ele, vector<int>&nums, int n, vector<vector<int>>&ds){
        // vector<int>ele;
        if(i == n){
            ds.push_back(ele);
            return;
        }
        ele.push_back(nums[i]);
        subsequence(i+1, ele, nums, n, ds);
        ele.pop_back();
        subsequence(i+1, ele, nums, n, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ds;
        vector<int>ele;
        int n = nums.size();
        subsequence(0, ele, nums, n, ds);
        return ds;
    }
};