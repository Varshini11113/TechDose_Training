class Solution {
public:
    int dp[38];
    int fibo(int n) {
        if(n == 2 || n == 1) return dp[n] = 1;
        if(n == 0) return dp[n] = 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fibo(n-1) + fibo(n-2) + fibo(n-3);
    }
    int tribonacci(int n){
        memset(dp, -1, sizeof(dp));
        return fibo(n);
    }
};