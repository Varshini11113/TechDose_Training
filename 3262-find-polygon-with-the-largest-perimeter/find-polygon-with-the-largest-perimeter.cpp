class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        vector<long long> arr(n);
        sort(nums.begin(), nums.end());
        arr[0] = nums[0];
        for(int i = 1; i<n; i++){
            arr[i] = arr[i-1]+nums[i];
        }
        for(int i = 2; i<n; i++){
            if(nums[i] < arr[i-1]){
                res = max(res, arr[i]);
            }
        }
        if(res == 0) res-=1;
        return res;
    }
};