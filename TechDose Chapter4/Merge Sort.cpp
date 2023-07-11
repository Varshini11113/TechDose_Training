#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    vector<int>temp;
    int left = l;
    int right = mid+1;
    while((left <= mid && right<= r)){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    while(right <= r){
        temp.push_back(arr[right++]);
    }
    for(int i = left; i<=right; i++){
        arr[i] = temp[i - low];
    }
}



void mergeSort(int arr[], int l, int r){
    if(l >= r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}




int main()  
{  
    int a[] = { 12, 31, 25, 8, 32, 17, 40, 42 };  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArray(a, n);  
    mergeSort(a, 0, n - 1);  
    printf("After sorting array elements are - \n");  
    printArray(a, n);  
    return 0;  
}  