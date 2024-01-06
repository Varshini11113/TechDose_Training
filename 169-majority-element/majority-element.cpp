class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, major = nums[0], n = nums.size();
        for(int i = 0; i<n; i++){
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