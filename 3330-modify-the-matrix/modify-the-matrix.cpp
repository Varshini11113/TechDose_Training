class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        vector<int>maxi(c, -1);
        for(int i = 0; i<c; i++){
            for(int j = 0; j<r; j++){
                ans[j][i] = matrix[j][i];
                maxi[i] = max(maxi[i], matrix[j][i]);
            }
            cout << maxi[i] << " ";
        }
        for(int i = 0; i<c; i++){
            for(int j = 0; j<r; j++){
                if(ans[j][i] == -1){
                    ans[j][i] = maxi[i];
                }
            }
        }
        return ans;
    }
};