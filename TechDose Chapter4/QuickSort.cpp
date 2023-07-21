//Quicksort algorithm
int partition(vector<int>&nums, int low, int high){
    int pivot = nums[low];
    int i = low;
    int j = high;
    while(i < j){
        while(nums[i] <= pivot && i <= high-1) i++;
        while(nums[j] > pivot && j >= low+1) j--;
        if(i < j) swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[low]);
    return j;
}
//here the first element is choosen as the pivot element

void quickSort(vector<int>&nums, int low, int high){
    if(low <= high){
        int pIdx = partition(nums, low, high);
        quickSort(nums, low, pIdx-1);
        quickSort(nums, pIdx+1, high);
    }
}

/*Time complexity
Best Case --> O(n log n) [middle element is the pivot]
Worst Case --> O(n^2) [array is already sorted so no swapping involved (or) if pivot element remains at the same place]
*/

/*Space Complexity --> O(1) in place*/