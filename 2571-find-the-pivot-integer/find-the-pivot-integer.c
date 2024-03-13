int pivotInteger(int n){
    long long int sum = 0, i, sum1 = 0;
    for(i = 1; i<=n; i++){
        sum+=i;
    }
    for(int i = 1; i<=n; i++){
        sum1+=i;
        if(sum1 * 2 - i == sum){
            return i;
        }
    }
return -1;
}