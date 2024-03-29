class Solution {
public:
    void perm(vector<int>&nums, vector<vector<int>>&res, int ind){
        if(ind == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = ind; i < nums.size(); i++){
            swap(nums[ind], nums[i]);
            perm(nums, res, ind+1);
            swap(nums[ind], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        perm(nums, res, 0);
        return res;
    }
};