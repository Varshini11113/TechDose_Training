class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(auto i : nums){
            if(i > ans[ans.size()-1]){
                ans.push_back(i);
            }
            else{
                auto it = lower_bound(ans.begin(), ans.end(), i);
                *it = i;
            }
        }
        return ans.size();
    }
};