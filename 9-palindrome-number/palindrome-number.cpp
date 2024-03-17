class Solution {
public:
    long long int reverse(int x){
        long long int n = 0;
        while(x > 0){
            // x /= 10;
            n = (n * 10) + (x%10);
            cout << n << " ";
            x /= 10;
        }
        return n;
    }
    bool isPalindrome(int x) {
        if( x < 0 ) return false;
        long long int n = reverse(x);
        return n == x;
    }
};