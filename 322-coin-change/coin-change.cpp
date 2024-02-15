class Solution {
public:
    int count(vector<int>&coins, int amount, int n,vector<vector<int>> &dp){
        if(n < 0) return 100000;
        if(amount == 0) return 0;
        if(dp[n][amount]!=-1)return dp[n][amount];

        int notIn = count(coins, amount, n - 1,dp);
        int in = 100000;
        if(amount >= coins[n]){
            in = 1 + count(coins, amount - coins[n], n,dp);
        }
        return dp[n][amount]=min(in, notIn);
    }
    int coinChange(vector<int>& coins, int amount) {
        int l=coins.size();
        vector<vector<int>> dp(l,vector<int>(amount+1,-1));
        int min = count(coins, amount, coins.size() - 1,dp);
        return min >= 100000 ? -1 : min;
    }
};