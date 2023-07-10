/*
Question Leetcode 201

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0
*/

//Solution 


//Flipped bit entire column 0
//All columns to the right of flipped bit is also flipped
//left consecutive common elements are fixed
 
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m = left, n = right;
        int count = 0;
        while(m != n){
            m>>=1;
            n>>=1;
            count++;
        }
        return m<<count;
    }
};
