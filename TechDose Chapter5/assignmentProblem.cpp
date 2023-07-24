/*
Question 1011. Capacity To Ship Packages Within D Days
Leetcode

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Approach

here, 
Goal is to find the minimum amount of weight
we know the ranges min & max.
So following Binary Search approach
*/

//Solution
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min = *max_element(weights.begin(), weights.end());
        int max = accumulate(weights.begin(), weights.end(), 0);
        cout<<min<<" "<<max;
        int mid;
        while(min <= max){
            mid = min + (max - min)/2;
            int daysCount = 1, currWeight = 0;
            for(auto weight : weights){
                if(currWeight + weight > mid){
                    daysCount++;
                    currWeight = 0;
                }
                currWeight += weight;
            }
            if(daysCount <= days){
                max = mid - 1;
            }
            else{
                min = mid + 1;
            }
        }
        return min;
    }
};