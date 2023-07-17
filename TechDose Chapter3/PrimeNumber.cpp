//program to find the prime number

//easy approach
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int n = 19, flag = false;
    for(int i = 2; i<sqrt(n); i++){
        if(n % i == 0){
            flag = true;
        }
    }
    return flag == false;
}

//seive of erathothenes
int main(){
    int n = 19;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int i = 2; i<=sqrt(n); i++){
        if(prime[i]){
            for(int j = i*i; j<=n; j+=i){
                prime[i] = false;
            }
        }
    }

    for(int i = 2; i<=n; i++){
        if(prime[i]){
            cout << i << ' ';
        }
    }
}

//Time complexity = O(N loglogN)