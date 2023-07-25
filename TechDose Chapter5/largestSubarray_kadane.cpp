/*
53. Maximum Subarray
Medium
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
*/

//solution

//Approach
/*
Kadane's algorithm
--> Two variables 
    max_so_far -- to store the maximum subarray value obtained so far
    maximum_sum -- to store the oeverall maximum sum value
--> main intuition 
    --> if sum is obtained to be negative then ignore it (max_so_far = 0)
    --> Everytime there is a positive-sum value in maximum_sum compare it with max_so_far and update max_so_far if it is greater than max_so_far.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if(max < sum){
                max = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return max;
    }
};