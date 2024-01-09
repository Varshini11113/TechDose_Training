// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
// Find catalan number
unsigned long int nCr(int n, int r)
{
    if (r > n - r)
    {
        r = n - r;
    }
    unsigned long int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main()
{
    // Write C++ code here
    // std::cout << "Hello world!";
    int n = 4;
    unsigned long int res = nCr(2 * n, n) / (n + 1);
    std ::cout << "Result is : " << res;
    return 0;
}