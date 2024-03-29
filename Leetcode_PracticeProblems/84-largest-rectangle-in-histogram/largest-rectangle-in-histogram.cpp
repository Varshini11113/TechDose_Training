class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>left(n), right(n);
        for(int i = 0; i<n; i++){
            if(st.empty()){
                left[i] = 0;
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                left[i] = (st.empty()) ? 0 : st.top() + 1;
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--){
            if(st.empty()){
                right[i] = n-1;
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                right[i] = (st.empty()) ? n-1 : st.top() - 1;
                st.push(i);
            }
        }
        int max_area = 0;
        for(int i = 0; i<n; i++){
            max_area = max(max_area, heights[i] * (right[i] - left[i] + 1));
        }
        return max_area;
    }
};