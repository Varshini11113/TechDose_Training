class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        for(int i = 0; i<order.length(); i++){
            mp[order[i]] = i;
        }
        string str = "";
        for(auto c : order){
            int count = 0;
            for(auto ch : s){
                if(ch == c){
                    count++;
                }
            }
            str.append(count, c);
        }
        for(char ch : s){
            if(mp.find(ch) == mp.end()){
                str.push_back(ch);
            }
        }
        return str;
    }
};