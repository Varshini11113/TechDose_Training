class Solution {
public:
    string helper(int &pos, string s){
        int n = s.size();
        int num = 0;
        string word = "";
        for(; pos < n; pos++){
            char ch = s[pos];
            if(ch == '['){
                string substr = helper(++pos, s);
                for(; num > 0; num--) word += substr;
            }
            else if(ch == ']'){
                return word;
            }
            else if(ch >= '0' && ch <= '9'){
                num = num*10 + ch - '0';
            }
            else{
                word += ch;
            }
        }
        return word;
    }
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }
};