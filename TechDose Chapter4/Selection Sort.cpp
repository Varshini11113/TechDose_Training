//Selection sort Algorithm 
//Time complexity: O(n^2);
//Space Complexity O(1) - inplace
#include <bits/stdc++.h>
using namespace std;


int arr[] = [5,4,6,7,8];
int n = 5;
for(int i = 0; i<n; i++){
    int minInd = i;
    for(int j = i+1; j<n; j++){
        if (arr[j] < arr[minInd]){
            minInd = j;
        }
    }
    if(minInd != i){
        swap(arr[minInd], arr[i]);
    }
}

//all code -- selection, insertion, bubble
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

selection sort
void selection(int arr[], int n){
    for(int i = 0; i<n; i++){
        int minInd = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minInd]){
                minInd = j;
            }
        }
        if(minInd != i){
            swap(arr[i], arr[minInd]);
        }
    }
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

bubble sort
void bubble(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int swaping = false;
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaping = true;
            }
        }
        if(swaping == false){
            break;
        }
    }
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}
insertion
void insertion(int arr[], int n){
    for(int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    int arr[5] = {5,1,2,7,3};
    // selection(arr, 5);
    // bubble sort
    // bubble(arr, 5);
    insertion(arr, 5);
    return 0;
}