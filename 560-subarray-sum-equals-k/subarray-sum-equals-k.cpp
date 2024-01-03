class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> target;
        int ans = 0;
        int n = nums.size();
        int sum = 0;
        target[sum] = 1;
        for(auto ele : nums){
            sum+=ele;
            if(target[sum - k] > 0){
                ans+=target[sum-k];
            }
            target[sum]++;
        }
        return ans;
    }
};