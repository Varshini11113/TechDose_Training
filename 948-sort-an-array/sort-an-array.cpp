class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high){
        vector<int>temp;
        int l = low, h = mid+1;
        while(l <= mid && h <= high){
            if(nums[l] <= nums[h]){
                temp.push_back(nums[l]);
                l++;
            }
            else{
                temp.push_back(nums[h]);
                h++;
            }
        }
        while(l <= mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(h <= high){
            temp.push_back(nums[h]);
            h++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }
    void mergesort(vector<int>&nums, int low, int high){
        int l = low, h = high;
        if(l >= h) return;
        int mid = l + (h - l)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, h);
        merge(nums, l, mid, h);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n-1);
        return nums;
    }
};