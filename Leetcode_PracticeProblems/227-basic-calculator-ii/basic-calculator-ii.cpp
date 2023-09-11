class Solution {
public:
    int calculate(string s) {
        if(s.length() == 0) return 0;
        stack<int>st;
        long long int curr = 0;
        char op = '+';
        for(unsigned int i = 0; i<s.length(); i++){
            char ch = s[i];
            if(isdigit(ch)){
                curr = 10*curr + ch - '0';
            }
            if(!isdigit(ch) && ch != ' ' || i == s.length()-1){
                if(op == '+'){
                    st.push(curr);
                }
                else if(op == '-'){
                    st.push(-curr);
                }
                else{
                    int num;
                    if(op == '*') num = st.top() * curr;
                    else num = st.top() / curr;
                    st.pop();
                    st.push(num);
                }
                op = ch;
                curr = 0;
            }
        }
        long long int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};