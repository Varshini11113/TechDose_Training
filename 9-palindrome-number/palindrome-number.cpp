class Solution {
public:
    bool isPalindrome(int x) {
        int newe = x;
        long long n = 0;
        while(x > 0){
            n = (n * 10) + (x % 10);
            cout << n << " ";
            x/=10;
        }
        return n == newe;
    }
};