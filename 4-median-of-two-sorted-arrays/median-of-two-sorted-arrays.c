int min(int x, int y){
    return x<y? x : y;
}
double findnthvalue(int *nums1,int nums1Size,int *nums2,int nums2Size,int n){
    if(nums2Size < nums1Size){
        return findnthvalue(nums2, nums2Size, nums1, nums1Size, n);
    }
    if(nums1Size == 0){
        return nums2[n - 1];
    }
    if(n == 1){
        return min(nums1[0], nums2[0]);
    }
    int half1 = min(nums1Size, n/2);
    int half2 = n - half1;
    if(nums1[half1 - 1] < nums2[half2 - 1]){
        return findnthvalue(nums1 + half1, nums1Size - half1, nums2, half2,n - half1);
    }
    if(nums2[half2 - 1] < nums1[half1 - 1]){
        return findnthvalue(nums1, half1, nums2 + half2, nums2Size- half2,n - half2);
    }
    return nums1[half1 - 1];
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sum = nums1Size + nums2Size;
    if(sum % 2 == 1){
        return findnthvalue(nums1, nums1Size, nums2, nums2Size, sum / 2 + 1);
    }
    else
    return (findnthvalue(nums1, nums1Size, nums2, nums2Size, sum / 2) + findnthvalue(nums1, nums1Size, nums2, nums2Size, sum / 2 + 1)) / 2.0;
}