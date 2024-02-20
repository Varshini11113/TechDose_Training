class Solution {
public:
    void combination(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds, int i, int target){
        // if(target == 0) return;
        if(i < 0){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            combination(candidates, ans, ds, i, target - candidates[i]);
            ds.pop_back();
        }
        combination(candidates, ans, ds, i-1, target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        combination(candidates, ans, ds, candidates.size()-1, target);
        return ans;
    }
};