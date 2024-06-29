class Solution {
public:
    vector<int>pascal(int n){
        vector<int>ans;
        ans.push_back(1);
        long long int answer = 1;
        for(int col = 1; col < n; col++){
            answer *= (n - col);
            answer /= col;
            ans.push_back(answer);
        }
        // ans.push_back(answer);
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int row = 1; row <= numRows; row++){
            res.push_back(pascal(row));
        }
        return res;
    }
};