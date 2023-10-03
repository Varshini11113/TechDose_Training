class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size(), X;
        for(int i = 1; i<=n+1; i++){
            X ^= i;//XOR of all the elements
        }
        for(int i = 1; i<n; i+=2){
            X ^= encoded[i];//odd elements
        }
        vector<int>ans;
        ans.push_back(X);
        for(int i = 0; i<n; i++){
            X ^= encoded[i];
            ans.push_back(X);
        }
        return ans;
    }
};