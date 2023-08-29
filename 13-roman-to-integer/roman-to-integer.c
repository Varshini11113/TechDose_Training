

int romanToInt(char * s){
    int arr[100];
    arr['\0'] = 0;
    arr['I'] = 1;
    arr['V'] = 5;
    arr['X'] = 10;
    arr['L'] = 50;
    arr['C'] = 100;
    arr['D'] = 500;
    arr['M'] = 1000;
    int n = strlen(s), sum = 0;
    for(int i = 0; i<n; i++){
        if(arr[s[i]] < arr[s[i+1]]){
            sum -= arr[s[i]];
        }
        else{
            sum += arr[s[i]];
        }
    }
    return sum;
}