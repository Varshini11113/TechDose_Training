//Bubble sort
//Time complexity : O(n^2) -> worst case
                    // O(n) -> best case using flag set
//Space Complexity - O(1) -> inplace
for(int i = 0; i<n-1; i++){
    int swap = false;
    for(int j = 0; j<n-i-1; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
            swap = true;
        }
    }
    if(swap == false) break;
}