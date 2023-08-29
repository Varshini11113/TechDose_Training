class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r =0, n = nums.size();
        int mini = INT_MAX, sum = 0;
        while(r < n){
            sum += nums[r];
            if(sum >= target){
                while(sum >= target){
                    sum -= nums[l];
                    l++;
                }
                mini = min(mini, r-l+2);
            }
            r++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};