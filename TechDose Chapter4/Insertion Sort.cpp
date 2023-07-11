//Insertion sort
//TimeComplexity: O(n^2)
//SpaceComplexity - inplace O(1);

//Solution:
for(int i = 1; i<n; i++){
    int temp = arr[i];
    int j = i-1;
    while((j>=0 && arr[j]>temp)){
        //swap
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
}