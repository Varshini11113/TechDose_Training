class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i = 0; i<n; i++){
            char ch = s[i];
            if(ch == '[' || ch == '{' || ch == '('){
                st.push(ch);
            }
            if(ch == ']' || ch == '}' || ch == ')'){
                if(st.empty()) return false;
                if(st.top() == '[' && ch == ']' || st.top() == '{' && ch == '}' || st.top() == '(' && ch == ')') st.pop();
                else
                return false;
            }
        }
        return st.empty();
    }
};