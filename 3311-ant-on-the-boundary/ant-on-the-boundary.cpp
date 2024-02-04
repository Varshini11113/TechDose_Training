class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int s = 0, c = 0;
        for(int i : nums){
            s += i;
            if(s == 0){
                c++;
            }
        }
        
        return c;
    }
};