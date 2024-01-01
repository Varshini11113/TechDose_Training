class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]% 2 == 0) {
                even++;
            }
            
        }
        if(even >= 2) return true;
        return false;
    }
};