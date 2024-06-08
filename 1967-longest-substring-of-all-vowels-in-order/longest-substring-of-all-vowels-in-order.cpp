class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();
        int maxlen = 0;
        //find beautiful string
        for(int i = 1; i<n; i++){
            if(word[i-1] == 'a'){
                int unique = 1, curr = 1;
                while(i < word.length() && word[i-1] <= word[i]){
                    unique += (word[i-1] < word[i]) ? 1 : 0;
                    curr++;
                    i++;
                }
                if(unique == 5){
                    maxlen = max(maxlen, curr);
                }
            }
            
        }
        return maxlen;
    }
};