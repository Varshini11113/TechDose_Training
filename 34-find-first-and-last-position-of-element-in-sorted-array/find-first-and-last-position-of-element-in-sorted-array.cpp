class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        int flag = 1;
        for(int i = 0; i<n; i++){
            if(nums[i] == target) {
                ans.push_back(i); 
                flag = 0;
                break;
            }
        }
        if(flag == 1) 
        ans.push_back(-1);
        int f2 = 0;
        for(int i = n-1; i>=0; i--) {
            if(nums[i] == target){
                ans.push_back(i);
                f2 = 1;
                break;
            }
        } 
        if(f2 == 0)
        ans.push_back(-1);
        return ans;
    }
};