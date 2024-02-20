class Solution {
public:
    void combination(vector<int>& candidates, vector<vector<int>>&ans, vector<int>& ds, int ind, int target){
        if(ind < 0){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            combination(candidates, ans, ds, ind, target - candidates[ind]);
            ds.pop_back();
        }
        combination(candidates, ans, ds, ind-1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = candidates.size();
        combination(candidates, ans, ds, n-1, target);
        return ans;
    }
};