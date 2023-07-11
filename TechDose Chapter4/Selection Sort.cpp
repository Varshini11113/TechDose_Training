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
