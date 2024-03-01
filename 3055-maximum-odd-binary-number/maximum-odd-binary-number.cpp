class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = countOnes(s);
        int zeroes = countZeroes(s);
        if(ones == 0) return "0";
        string result = builtResult(ones, zeroes);
        return result;
    }
private:
    int countOnes(string s){
        return count(s.begin(), s.end(), '1');
    }
    int countZeroes(string s){
        return count(s.begin(), s.end(), '0');
    }
    string builtResult(int ones, int zeroes){
        string result = "1";
        ones--;
        result = string(zeroes, '0')+result;
        result = string(ones, '1')+result;
        return result;
    }
};