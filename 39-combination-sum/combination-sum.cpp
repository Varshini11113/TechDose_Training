class Solution {
public:
    void combination(vector<int>&candidates, int target, vector<int>combo, int currSum, int currIndex, vector<vector<int>> &ans){
        if(currSum > target) return;
        if(currSum == target){
            ans.push_back(combo);
            return;
        }
        for(int i = currIndex; i<candidates.size(); i++){
            combo.push_back(candidates[i]);
            currSum += candidates[i];
            combination(candidates, target, combo, currSum, i, ans);
            combo.pop_back();
            currSum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>combo;
        combination(candidates, target, combo, 0, 0, ans);
        return ans;
    }
};