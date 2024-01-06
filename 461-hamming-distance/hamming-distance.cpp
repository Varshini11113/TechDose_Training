class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = 0, n = x^y;
        while(n){
            d++;
            n &= (n-1);
        }
        return d;
    }
};