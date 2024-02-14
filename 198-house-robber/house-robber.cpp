class Solution {
public:
    vector<int> memo;

    int robbing(vector<int>& nums, int i) {
        if (i < 0) {
            return 0;
        }
        if (memo[i] >= 0) {
            return memo[i];
        }
        int result = max(robbing(nums, i - 2) + nums[i], robbing(nums, i - 1));
        memo[i] = result;
        return result;
    }

    int rob(vector<int>& nums) {
        memo.resize(nums.size() + 1, -1);
        return robbing(nums, nums.size() - 1);
    }
};