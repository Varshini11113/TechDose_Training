class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for(int i = 0; i<=n; i++){
            tot += i;
        }
        int curr = 0;
        for(int i = 0; i<n; i++){
            curr += nums[i];
        }
        cout << tot << " " << curr << " ";
        return tot - curr;
    }
};