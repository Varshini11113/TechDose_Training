class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), curr = 0, maxLen = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                maxLen = max(maxLen, ++curr);
            }
            else{
                curr = 0;
            }
        }
        return maxLen;
    }
};