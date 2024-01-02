class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &i : nums){
            mp[i]++;
        }
        vector<vector<int>>ans;
        while(!mp.empty()){
            vector<int>row;
            vector<int>remove;
            for(auto &[f, s] : mp){
                row.push_back(f);
                s--;
                if(s == 0) remove.push_back(f);
            }
            ans.push_back(row);
            for(auto &i : remove){
                mp.erase(i);
            }
        }
        return ans;
    }
};