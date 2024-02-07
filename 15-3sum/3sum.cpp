class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            int target = -nums[i];
            int left = i+1;
            int right = n-1;
            while(left < right){
                if(nums[left] + nums[right] < target){
                    left++;
                }
                else if(nums[left] + nums[right] > target){
                    right--;
                }
                else{
                    vector<int> tri = {nums[i], nums[left], nums[right]};
                    res.push_back(tri);
                    while(left < right && nums[left] == tri[1]){
                        left++;
                    }
                    while(left < right && nums[right] == tri[2]){
                        right--;
                    }
                }  
            }
            while(i+1 < n && nums[i] == nums[i+1]){
                        i++;
            }
        }
        return res;
    }
};