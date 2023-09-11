class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>map;
        priority_queue<pair<int, char>>pq;
        for(char c : s){
            map[c]++;
        }
        for(auto ch : map){
            pq.push({ch.second, ch.first});
        }
        string str = "";
        while(!pq.empty()){
            str += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return str;
    }
};