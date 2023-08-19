class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>m;
        priority_queue<pair<int, int>>pq;
        vector<int>res;
        for(int i = 0; i<n; i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            pq.push(make_pair(i.second, i.first));
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};