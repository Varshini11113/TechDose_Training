class Solution {
public:
    // int partition(vector<int>&nums, int low, int high){
    //     int pivot = nums[high];
    //     int i = low - 1;
    //     for(int j = low; j<=high; j++){
    //         if(nums[j] < pivot){
    //             i++;
    //             swap(nums[i], nums[j]);
    //         }
    //     }
    //     swap(nums[i+1], nums[high]);
    //     return i+1;
    // }

    // void quicksort(vector<int>&nums, int low, int high){
    //     if(low < high){
    //         int p = partition(nums, low, high);
    //         quicksort(nums, low, p-1);
    //         quicksort(nums, p+1, high);
    //     }
    // }
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
        for(int i = low; i<=high; i++){
            nums[i] = temp[i - low];
            // ind++;
        }
    }

    void mergesort(vector<int>&nums, int low, int high){
        int l = low, h = high;
        if(l >= h) return;
        int mid = l + (h-l)/2;
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