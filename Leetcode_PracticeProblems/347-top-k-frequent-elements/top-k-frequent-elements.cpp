class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>m;
        priority_queue<pair<int, int>>pq;
        vector<int>res;
        for(auto i : nums){
            m[i]++;
        }
        for(auto i : m){
            pq.push({i.second, i.first});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};