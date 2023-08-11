class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, l1 = nums1.size(), l2 = nums2.size();
        vector<int> ans;
        while(i < l1){
            auto itr = find(nums2.begin(), nums2.end(), nums1[i]);
            j = itr - nums2.begin();
            while(j < l2){
                if(nums1[i] < nums2[j]){
                    ans.push_back(nums2[j]);
                    break;
                }
                j++;
            }
            if(j == l2) ans.push_back(-1);
            i++;
        }
        return ans;
    }
};
