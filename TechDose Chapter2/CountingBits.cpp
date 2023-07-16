/*
Question : 338 (leetcode)

338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/

//solution -> if odd = 1 + setbit
            //   if even = setbit;

class Solution {
public:
    vector<int> countBits(int n) {
        //set bits even -> setbit 
        //odd = 1 + setbit
        vector<int>ans(n+1);
        ans[0] = 0;
        for(int i = 1; i<=n; i++){
            ans[i] = (ans[i/2] + i % 2);
            // else ans[i] = ans[i/2];
        }
        return ans;
    }
};