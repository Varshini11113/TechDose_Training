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