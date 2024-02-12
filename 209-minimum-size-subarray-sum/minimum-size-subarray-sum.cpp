class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, ans = 0, minSub = INT_MAX;
        while(right < n){
            ans += nums[right];
            if(ans >= target){
                while(ans >= target){
                    ans -= nums[left];
                    left++;
                }
                minSub = min(minSub, (right - left + 2));
            }
            right++;
        }
        return minSub == INT_MAX ? 0 : minSub;
    }
};