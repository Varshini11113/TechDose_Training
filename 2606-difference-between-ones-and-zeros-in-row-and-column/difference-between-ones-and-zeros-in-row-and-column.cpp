class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<int> row(r);
        vector<int> col(c);
        vector<vector<int>> diff(r, vector<int>(c,0));
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 1){
                    row[i] += grid[i][j];
                    col[j] += grid[i][j];
                }
            }
        }
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                diff[i][j] = (2 * row[i] - r) + (2 * col[j] - c);
            }
        }
        return diff;
    }
};