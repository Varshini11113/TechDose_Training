class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long>mp;
        multiset<long long>st;
        vector<long long>ans;
        for(int i = 0; i<nums.size(); i++){
            long long val = mp[nums[i]];
            if(st.count(val)){
                st.erase(st.find(val));
            }
            mp[nums[i]] += freq[i];
            st.insert(mp[nums[i]]);
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};