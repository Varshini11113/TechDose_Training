class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        int p = 1<<n;
        for(int mask = 0; mask<p; mask++){
            vector<int>seb;
            for(int i = 0; i<n; i++){
                if(mask & (1<<i)){
                    seb.push_back(nums[i]);
                }
            }
            ans.push_back(seb);
        }
        return ans;
    }
};