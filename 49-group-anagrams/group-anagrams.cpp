class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>>mp;
        vector<string> temp = strs;
        for(int i = 0; i<temp.size(); i++){
            string val = temp[i];
            sort(temp[i].begin(), temp[i].end());
            mp[temp[i]].push_back(val);
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};