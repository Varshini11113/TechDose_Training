class Solution {
public:
    void subsets(int i, vector<vector<int>>&ds, vector<int>&ele, vector<int>&nums, int n){
        ds.push_back(ele);
        for(int j = i; j<n; j++){
            if(j != i && nums[j] == nums[j-1]) continue;
            ele.push_back(nums[j]);
            subsets(j+1, ds, ele, nums, n);
            ele.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ds;
        vector<int>ele;
        sort(nums.begin(), nums.end());
        subsets(0, ds, ele, nums, n);
        return ds;
    }
};