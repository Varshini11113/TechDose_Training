//Leetcode question no 164. Maximum Gap
/*Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.*/

/*Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.*/

//SOLUTION using Radix sort

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return abs(nums[0] - nums[1]);
        int exp = 1;
        int maxDigit = log10(*max_element(nums.begin(), nums.end()))+1;
        // cout<<maxDigit;
        while(maxDigit--){
            vector<int>output(n);
            vector<int>count(10,0);
            for(int i = 0; i<n; i++){
                int digit = (int)(nums[i]/exp)%10;
                count[digit]++;
            }
            for(int i = 1; i<10; i++){
                count[i] += count[i-1];
                cout<<count[i];
            }
            for(int i = n-1; i>=0; i--){
                int digit = (int)(nums[i]/exp)%10;
                output[count[digit]-1] = nums[i];
                // cout<<output[i];
                count[digit]--;
                // cout<<count[i];
            }
            for(int i = 0; i<n; i++){
                nums[i] = output[i];
                // cout<<nums[i];
            }
            exp*=10;
        }
        int maxi = 0;
        for(int i = 1; i<n; i++){
            maxi = max(maxi, (nums[i] - nums[i-1]));
        }
        return maxi;
    }
};