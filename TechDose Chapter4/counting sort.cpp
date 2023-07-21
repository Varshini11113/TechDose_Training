//Counter sort

/*Step1 --> create a frequency array

Step2 --> form cumulative array

Step3 --> traverse through the array and place the element in the output array*/


void countSort(vector<int>&nums){
    int n = nums.size();
    vector<int>output(n);
    vector<int>count(10,0);
    //step1
    for(int i = 0; i<n; i++){
        count[nums[i]]++;
    }
    //step2
    for(int i = 1; i<10; i++){
        count[i] += count[i-1];
    }
    //step3
    for(int i = n-1; i>=0; i--){
        output[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }
    //placing the sorted array in the output array
    for(int i = 0; i<n; i++){
        output[i] = nums[i];
    }
}

//Time Complexity --> O(N + R + N) --> O(N + R)
//Space Complexity --> O(1) inplace