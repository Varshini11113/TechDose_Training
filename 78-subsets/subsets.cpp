class Solution {
public:
    void subsequence(int i, vector<int>&ele, vector<int>&nums, vector<vector<int>>&ds, int n){
        if(i == n){
            ds.push_back(ele);
            return;
        }
        ele.push_back(nums[i]);
        subsequence(i+1, ele, nums, ds, n);
        ele.pop_back();
        subsequence(i+1, ele, nums, ds, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>ele;
        vector<vector<int>>ds;
        subsequence(0, ele, nums, ds, n);
        return ds;
    }
};