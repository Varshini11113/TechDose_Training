class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_max = 0, curr_min = 0, max_sub = INT_MIN, min_sub = INT_MAX, total = 0;
        for(auto i : nums){
            total += i;
            curr_max += i;
            curr_min += i;
            max_sub = max(max_sub, curr_max);
            min_sub = min(min_sub, curr_min);
            if(curr_min > 0) curr_min = 0;
            if(curr_max < 0) curr_max = 0;
        }
        return total == curr_min ? max_sub : max(max_sub, total - min_sub);
    }
};