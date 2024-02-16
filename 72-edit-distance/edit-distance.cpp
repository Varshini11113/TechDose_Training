class Solution {
public:
    int dp[501][501];
    int convert(string s1, string s2, int m, int n){
        if(m == 0) return n;
        if(n == 0) return m;
        if(dp[m][n] != -1) return dp[m][n];
        if(s1[m-1] == s2[n-1]) 
            return convert(s1, s2, m-1, n-1);
        // int insert = 1 + convert(s1, s2, m, n-1);
        // int remove = 1 + convert(s1, s2, m-1, n);
        // int edit = 1 + convert(s1, s2, m-1, n-1);
        dp[m][n] = 1 + min(min(convert(s1, s2, m, n-1), convert(s1, s2, m-1, n)), convert(s1, s2, m-1, n-1));
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        int m = word1.size(), n = word2.size();
        return convert(word1, word2, m, n);
    }
};