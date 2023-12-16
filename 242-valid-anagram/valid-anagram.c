bool isAnagram(char * s, char * t){ // s = eat t = atu
    if(strlen(s) != strlen(t)) return false;
    int arr[26] = {0};
    for(int i = 0; i<strlen(s); i++){//1st string iterate
        arr[s[i]-'a']++; //arr[4]++; arr[4] = 1; //arr[0]++ = arr[0] = 0;
    }
    for(int i = 0; i<strlen(t); i++){
        int x = --arr[t[i]-'a'];
        if(x < 0){
            return false;
        }
    }
    return true;
}