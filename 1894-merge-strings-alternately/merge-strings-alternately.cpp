class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        string str = "";
        int i = 0, j = 0;
        while(i < n1 || j < n2){
            if(i < n1)
            str.push_back(word1[i]);
            if(j < n2)
            str.push_back(word2[j]);
            i++;
            j++;
        }
        return str;
    }
};