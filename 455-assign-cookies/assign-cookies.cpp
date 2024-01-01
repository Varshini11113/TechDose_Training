class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int c = 0, j = -1;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0; i<g.size(); i++){
            while(++j < s.size()){
                if(s[j] >= g[i]){
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};