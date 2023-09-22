class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        int j = 0;
        for(int i = 0; i<n2 && j<n1; i++){
            if(s[j] == t[i]) j++;
        }
        if(j == n1) return true;
        return false;
    }
};