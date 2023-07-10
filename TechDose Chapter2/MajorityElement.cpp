/*

Question no 169 (leetcode)

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

//Solution simple 1) sort 2) return nums[n/2]

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};

//Solution 2 (atleast one element count will be 1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1, major = nums[0];
        for(int i = 1; i<n; i++){
            if(major == nums[i]){
                count++;
            }
            else{
                count--;
                if(count == 0){
                major = nums[i];
                count = 1;
                }
            }
        }
        return major;
};