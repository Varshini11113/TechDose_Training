class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long int rev = 0;
        while(temp > 0){
            int u = temp % 10;
            rev = rev*10+u;
            temp/=10;
        }
        if(x == rev){
            return true;
        }
        else{
            return false;
        }
    }
};