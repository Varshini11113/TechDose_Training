class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count = 0, sum = 0;
        for(auto i : nums){
            sum+=i;
            if(sum == 0 && i != 0){
                count++;
            }
        }
        return count;
    }
};