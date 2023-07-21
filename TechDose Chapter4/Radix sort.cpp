//Radix sort

/*similar to counting sort.

The counting sort is repeated for each digit of the number

Main goal is to get the maximum element's no of digit

The loop will run until all the digits get over and the counting sort is repeated for all the digits*/

void radixSort(vector<int>&nums){
    int n = nums.size();
    //finding maximum element
    int max_num=*max_element(nums.begin(), nums.end());
    //finding the no of digits using log function
    int maxDigits=(log10((double)abs(max_num))+1);
    int exp = 1; //to get the ones, tens,.. digits
    while(maxDigits--){
        //following the counting sort
        vector<int>output(n);
        vector<int>count(10,0);
        //step1 --> frequency array
        for(int i = 0; i<n; i++){
            int digit = (int)(nums[i]/exp)%10; //digit by digit
            count[digit]++;
        }
        //finding cumulative frequency array
        for(int i = 1; i<10; i++){
            count[i] += count[i-1];
        }
        //finding the correct position and placing it in the output array
        for(int i = n-1; i>=0; i--){
            int digit = (int)(nums[i]/exp)%10;
            output[count[digit] - 1] = nums[i];
            count[digit]--;
        }
        //rearranging the elements to get input for the next iteration
        for(int i = 0; i<n; i++){
            nums[i] = output[i];
        }
        exp*=10; //to get the next digit (ones --> tens, tens --> hundreds, etc..)
    }
}

/*Time complexity : Counting Sort --> O(N+b)
                    Radix Sort --> d*(O(N+b))
                    
                    For short inputs the TC will be O(n)
                    Derivation
                    --> d ==> (N+b)*log(k)
                    k <= N^c
                    b === N
                    N^c === c
                    so,
                    d ==> (N+N)*log(N^c)
                          (N+N)*log(c)
                          (N+N)*c
                          O(2Nc) ==> O(N);
                    */

//overall time complexity
/*T.C --> d*(O(n+b))
for short inputs --> O(N)
*/

//Space Complexity --> O(1) inplace
                    