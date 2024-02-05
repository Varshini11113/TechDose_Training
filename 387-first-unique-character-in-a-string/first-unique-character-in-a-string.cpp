class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int>map;
        int n = s.length();
        for(int i = 0; i<n; i++){
            map[s[i]]++;
        }
        for(int i = 0; i<n; i++){
            if(map[s[i]] == 1)
            return i;
        }
        return -1;
        
    }
};