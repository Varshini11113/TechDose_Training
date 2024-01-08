class Solution {
public:
    vector<int>nCr(int row){
        long long ans = 1;
        vector<int>res;
        res.push_back(1);
        for(int i = 1; i<row; i++){
            ans  *= (row - i);
            ans /= i;
            res.push_back(ans);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>>ans;
        for(int i = 1; i<=n; i++){
            ans.push_back(nCr(i));
        }
        return ans;
    }
};