class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        if (numRows == 0){ return {{}}; }
        if (numRows == 1){ return {{1}}; }

        vector<vector<int>> result = {{1}};

        for (int i = 1; i < numRows; i++){
            vector<int> a = {1};
            // First element of each row is always 1
            for (int j = 1; j < i; j++) {
                a.push_back(result[i - 1][j] + result[i - 1][j - 1]);
            }
            a.push_back(1); // Last element of each row is always 1
            result.push_back(a);
        }
    
        return result;
    }
};