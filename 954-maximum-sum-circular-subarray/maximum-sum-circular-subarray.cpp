class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_max = 0, curr_min = 0, maxSub = INT_MIN, minSub = INT_MAX;
        int tot = 0;
        for(int i : nums){
            tot += i;
            curr_max += i;
            curr_min += i;
            maxSub = max(maxSub, curr_max);
            minSub = min(minSub, curr_min);
            if(curr_max < 0) curr_max = 0;
            if(curr_min > 0) curr_min = 0;
        }
        return tot == curr_min ? maxSub : max(maxSub, tot - minSub); 
    }
};