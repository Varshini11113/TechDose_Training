class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, ans = 0, maxS = INT_MAX;
        while(right < n){
            ans += nums[right];
            if(ans >= target){
                while(ans >= target){
                    ans -= nums[left];
                    left++;
                }
                maxS = min(maxS, (right - left + 2));
            }
            right++;
        }
        return maxS == INT_MAX ? 0 : maxS;
    }
};