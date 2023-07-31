/*
Leetcode question no - 1755
1755. Closest Subsequence Sum

Question:

You are given an integer array nums and an integer goal.

You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

Return the minimum possible value of abs(sum - goal).

Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

 

Example 1:

Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.
Example 2:

Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
*/

//solution
class Solution {
public:
    //to find all subsets
    void find(vector<int>&arr, vector<int>&res){
        int n = arr.size();
        for(int i = 0; i<(1<<n); i++){
            int sum = 0;
            for(int j = 0; j<n; j++){
                if(i & (1<<j)) sum+=arr[j];
            }
            res.push_back(sum);
        }
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        //divide array into two halves
        vector<int>arr1;
        vector<int>arr2;
        for(int i = 0; i<n/2; i++) arr1.push_back(nums[i]);
        for(int i = n/2; i<n; i++) arr2.push_back(nums[i]);
        //find all subsets
        vector<int>res1;
        vector<int>res2;
        find(arr1, res1);
        find(arr2, res2);
        //finding the abs(sum - goal) value
        //sorting
        // sort(res1.begin(), res1.end());
        sort(res2.begin(), res2.end());
        int ans = INT_MAX;
        for(auto ele : res1){
            int l = 0, sum = 0;
            int r = res2.size()-1;
            while(l <= r){
                int mid = l + (r - l)/2;
                sum = ele +  res2[mid];
                if(sum == goal) return 0;
                ans = min(ans, abs(sum - goal));
                if(sum > goal){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return ans;
    }
};