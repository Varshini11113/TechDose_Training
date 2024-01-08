class Solution {
public:
    double myPow(double x, int n) {
        long p = labs(n);
        double res = 1;
        while(p){
            if(p % 2 == 1){
                res *= x;
            }
            x*=x;
            p/=2;
        }
        return n > 0 ? res : 1/res;
    }
};