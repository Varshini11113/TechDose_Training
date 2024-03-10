class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>n1(nums1.begin(), nums1.end());
        vector<int>res;
        for(int i : nums2){
            if(n1.count(i)){
                res.push_back(i);
                n1.erase(i);
            }
        }
        return res;
    }
};