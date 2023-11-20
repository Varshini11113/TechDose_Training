class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // int j = 0;
        int dir = 1, top = 0, down = n-1, left = 0, right = m-1;
        vector<int>result;
        while(top<=down && left <= right){
            if(dir == 1){
                for(int i = left; i<=right; i++){
                    result.push_back(matrix[top][i]);
                }
                dir = 2;
                top += 1;
            }
            else if(dir == 2){
                for(int i = top; i <= down; i++){
                    result.push_back(matrix[i][right]);
                }
                dir = 3;
                right -= 1;
            }
            else if(dir == 3){
                for(int i = right; i>=left; i--){
                    result.push_back(matrix[down][i]);
                }
                dir = 4;
                down -= 1;
            }
            else if(dir == 4){
                for(int i = down; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                dir = 1;
                left += 1;
            }
            // dir = (dir+1)%4;
        }
        return result;
    }
};