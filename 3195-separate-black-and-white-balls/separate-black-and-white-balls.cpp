class Solution {
public:
    long long minimumSteps(string s) {
        long long zerosCount = 0;
        for(auto i : s){
            if(i=='0') zerosCount++;
        }
        long long i = 0;
        long long curr = 0, ans = 0;
        while(i < s.size()){
            if(s[i] == '0'){
                ans = ans + i - curr;
                curr++;
            }
            i++;
        }
        return ans;
    }
};