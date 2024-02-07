class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1, lm = 0, rm = 0, res = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > lm){
                    lm = height[left];
                }
                else{
                    res += lm - height[left];
                }
                left++;
            }
            else{
                if(height[right] > rm){
                    rm = height[right];
                }
                else{
                    res += rm - height[right];
                }
                right--;
            }
        }
        return res;
    }
};