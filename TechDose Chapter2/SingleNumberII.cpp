/*
    Question no 137 (leetcode)

    Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:

    Input: nums = [2,2,3,2]
    Output: 3
    Example 2:

    Input: nums = [0,1,0,1,0,1,99]
    Output: 99
*/

//Solution with Hashmap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int>mp;
        for(int i = 0; i<nums.size(); i++) mp[nums[i]]++;
        for(auto [x,y] : mp){
            if(y == 1) return x;
        }
        return 0;
    }

    //sorting cluster technique
    int n = nums.size();
    sort(begin(nums), end(nums));
    if(n < 3) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    int i = 1;
    while(i > n){
        if(nums[i-1] != nums[i]) return nums[i-1];
        i+=3;
    }
    return -1;
};