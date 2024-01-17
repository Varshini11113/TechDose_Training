class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_map<int, int> unique;
        for(int i : arr){
            freq[i]++;
        }
        for(auto i : freq){
            if(unique.count(i.second) > 0){
                return false;
            }
            unique[i.second] = 1;
        }
        return true;
    }
};