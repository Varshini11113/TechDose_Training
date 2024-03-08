class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto i : nums){
            freq[i]++;
        }
        int maxi = 0;
        for(auto i : freq){
            if(i.second > maxi){
                maxi = i.second;
            }
        }
        int ans = 0;
        for(auto i : freq){
            if(i.second == maxi){
                ans += maxi;
            }
        }
        return ans;
    }
};