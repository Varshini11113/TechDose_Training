class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        int n = s.length();
        for(int i = 0; i<n; i++){
            arr[s[i] - 'a']++;
        }
        for(int i = 0; i<n; i++){
            if(arr[s[i] - 'a'] == 1)
            return i;
        }
        return -1;
        
    }
};