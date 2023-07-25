/*215. Kth Largest Element in an Array (leetcode)

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4*/

//solution
//QuickSelect
class Solution {
public:
    int partition(vector<int>&nums, int left, int right){
        int i = left;
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
        if(left < right){
            int position = partition(nums, left, right);
            if(position == target) return nums[target];
            else if(position > target) return quickSelect(nums, left, position - 1, target);
            else{
                return quickSelect(nums, position+1, right, target);
            }
        }
        return nums[target];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), target = n-k, left = 0, right = n-1;
        return quickSelect(nums, left, right, target);
    }
};