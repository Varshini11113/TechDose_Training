/*
Question Leetcode 461

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them.

Example 1:
Input: x = 1, y = 4
Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
*/

//Solution XOR, &
class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = 0, n = x ^ y;
        while(n){
            d++;
            n &= (n-1);
        }
        return d;
    }

    //beats 100% 
    class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        string s = bitset<32>(x).to_string();
        string s2 = bitset<32>(y).to_string();
        for(int i = 0; i<32; i++){
            if(s[i] != s2[i]){
                count++;
            }
        }
        return count;
    }
};
}; 
