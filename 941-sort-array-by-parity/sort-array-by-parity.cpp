class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        // int flag = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 0){
                ans.push_back(nums[i]);
            }
        }
         for(int i = 0; i<n; i++){
            if(nums[i] % 2 != 0){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};