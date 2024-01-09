class Solution {
public:
    unsigned long int fact(int n, int r){
        unsigned long int res = 1;
        if(r > n-r){
            r = n-r;
        }
        for(int i = 0; i<r; i++){
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    int numTrees(int n) {
        int res = fact(2*n, n) / (n+1);
        return res;
    }
};