class Solution {
public:
    int tribonacci(int n) {
        int T0 = 0, T1 = 1, T2 = 1, Tn;
        if(n == 0){
            return 0;
        }
        for(int i = 3; i<=n; i++){
            Tn = T0 + T1+ T2;
            T0 = T1;
            T1 = T2;
            T2 = Tn;
        }
        return T2;
    }
};