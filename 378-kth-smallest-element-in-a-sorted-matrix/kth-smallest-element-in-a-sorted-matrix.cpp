class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int>kthvalue;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                kthvalue.push(matrix[i][j]);
                if(kthvalue.size() > k) kthvalue.pop();
            }
        }
        return kthvalue.top();
    }
};