class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();
        for(int i = 0; i<n-1; i++){
            if((s[i] % 2 == 0 && s[i+1] % 2 == 0) || (s[i] % 2 != 0 && s[i+1] % 2 != 0)){
                if(s[i] > s[i+1]){
                    char temp = s[i];
                    s[i] = s[i+1];
                    s[i+1] = temp;
                    break;
                }
            }
        }
        return s;
    }
};