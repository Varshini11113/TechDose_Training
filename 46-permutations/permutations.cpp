class Solution {
public:
    vector<int>swap(vector<int>&nums, int l, int i){
        int temp = nums[l];
        nums[l] = nums[i];
        nums[i] = temp;
        return nums;
    }
    void perm(vector<int>&nums, int l, int r, vector<vector<int>>&res){
        if(l == r){
            res.push_back(nums);
            return;
        }
        for(int i = l; i<=r; i++){
            nums = swap(nums, l, i);
            perm(nums, l+1, r, res);
            nums = swap(nums, l, i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        perm(nums, 0, nums.size()-1, res);
        return res;
    }
};