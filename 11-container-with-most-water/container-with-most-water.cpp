class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), left = 0, right = n-1;
        int area = 0;
        while(left < right){
            area = max(area, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};