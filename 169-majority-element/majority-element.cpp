class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int i : nums){
            mp[i]++;
        }
        int count = 0, val;
        for(auto i : mp){
            if(i.second > count){
                count = i.second;
                val = i.first;
            }
        }
        if(count > nums.size()/2){
            return val;
        }
        return -1;
    }
};