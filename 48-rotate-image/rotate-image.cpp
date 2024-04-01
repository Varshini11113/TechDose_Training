class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>res(n, vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res[i][j] = matrix[j][i];
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i<n; i++){
            reverse(res[i].begin(), res[i].end());
        }
        matrix = res;
    }   
};