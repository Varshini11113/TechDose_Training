class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nge;
        stack<int>s;
        int n = nums2.size();
        for(int i = n-1; i>=0; i--){
            while(!s.empty() && s.top() < nums2[i]){
                s.pop();
            }
            if(!s.empty()){
                nge[nums2[i]] = s.top();
            }
            else{
                nge[nums2[i]] = -1;
            }
            s.push(nums2[i]);
        }
        vector<int>res;
        for(int i = 0; i<nums1.size(); i++){
            res.push_back(nge[nums1[i]]);
        }
        return res;
    }
};