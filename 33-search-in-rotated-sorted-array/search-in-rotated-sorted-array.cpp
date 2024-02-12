class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, k = target;
        int mid = low + (high - low) / 2;
        while(low <= high){
            if(nums[mid] == k) return mid;
            //check for sorted array
            //if left side sorted
            if(nums[low] <= nums[mid]){
                //check if the target is inside the boundary
                if(nums[low] <= k && k <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }                
            }
            //if right side sorted
            else{
                //check if the target is inside the boundary
                if(nums[mid] <= k && k <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            mid = low + (high - low) / 2;
        }
        return -1;
    }
};