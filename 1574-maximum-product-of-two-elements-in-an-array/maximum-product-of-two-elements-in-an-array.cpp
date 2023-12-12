class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1, max_prod = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                prod = ((nums[i] - 1) * (nums[j] - 1));
                if( prod > max_prod){
                    max_prod = prod;
                }
            }
        }
        return max_prod;
    }
};