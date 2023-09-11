class Solution {
public:
    int partition(vector<int>&nums, int left, int right){
        int i = left, n = nums.size();
        int pivot = nums[right];
        for(int j = left; j<right; j++){
            if(nums[j] <= pivot){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        nums[right] = nums[i];
        nums[i] = pivot;
        return i;
    }

    int quickSelect(vector<int>&nums, int left, int right, int target){
        int n = nums.size();
            while(left <= right){
            int position = partition(nums, left, right);
            if(position == target) return nums[position];
            else if(position > target) return quickSelect(nums, left, position - 1, target);
            else return quickSelect(nums, position + 1, right, target);
        }
        return -1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), target = n - k;
        int left = 0, right = n-1;
        return quickSelect(nums, left, right, target);
    }
};