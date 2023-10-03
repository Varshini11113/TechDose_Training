class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p = (1<<n);
        vector<vector<int>> ans(p);
        for(int num = 0; num < p; num++){
            for(int i = 0; i<n; i++){
                if(num & (1<<i))
                    ans[num].push_back(nums[i]);
            }
            // ans.push_back(sub);
        }
        return ans;
    }
};