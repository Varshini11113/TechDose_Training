class Solution {
public:
    void combination(vector<int>&candidates, int target, vector<int>combo, int currSum, int currIndex, vector<vector<int>> &ans){
        if(currSum > target) return;
        if(currSum == target){
            ans.push_back(combo);
            return;
        }
        for(int i = currIndex; i<candidates.size(); i++){
            if(i != currIndex && candidates[i] == candidates[i-1]) continue;
            combo.push_back(candidates[i]);
            currSum += candidates[i];
            combination(candidates, target, combo, currSum, i+1, ans);
            combo.pop_back();
            currSum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>combo;
        combination(candidates, target, combo, 0, 0, ans);
        return ans;
    }
};