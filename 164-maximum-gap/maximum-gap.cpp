class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return abs(nums[0] - nums[1]);
        sort(nums.begin(), nums.end());
        // int exp = 1;
        // int maxDigit = log10(*max_element(nums.begin(), nums.end()))+1;
        // // cout<<maxDigit;
        // while(maxDigit--){
        //     vector<int>output(n);
        //     vector<int>count(10,0);
        //     for(int i = 0; i<n; i++){
        //         int digit = (int)(nums[i]/exp)%10;
        //         count[digit]++;
        //     }
        //     for(int i = 1; i<10; i++){
        //         count[i] += count[i-1];
        //         cout<<count[i];
        //     }
        //     for(int i = n-1; i>=0; i--){
        //         int digit = (int)(nums[i]/exp)%10;
        //         output[count[digit]-1] = nums[i];
        //         // cout<<output[i];
        //         count[digit]--;
        //         // cout<<count[i];
        //     }
        //     for(int i = 0; i<n; i++){
        //         nums[i] = output[i];
        //         // cout<<nums[i];
        //     }
        //     exp*=10;
        // }
        int maxi = 0;
        for(int i = 1; i<n; i++){
            maxi = max(maxi, (nums[i] - nums[i-1]));
        }
        return maxi;
    }
};