/*
56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/

//solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(auto ele : intervals){
            if(ans.back()[1] >= ele[0]){
                ans.back()[1] = max(ans.back()[1], ele[1]);
            }
            else{
                ans.push_back(ele);
            }
        }
        return ans;
    }
};