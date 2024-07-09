class Solution {
public:
    string getEncryptedString(string s, int k) {
        string str = "";
        int n = s.length();
        for(int i = 0; i<n; i++){
            str += s[(i+k)%n];
        }
        return str;
    }
};