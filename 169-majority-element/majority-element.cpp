class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), major = nums[0], count = 1;
        for(int i = 1; i<n; i++){
            if(nums[i] == major){
                count++;
            }
            else{
                count--;
                if(count == 0){
                    major = nums[i];
                    count = 1;
                }
            }
        }
        return major;
    }
};