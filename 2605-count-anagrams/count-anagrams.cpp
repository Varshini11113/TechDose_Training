class Solution {
public:
    const long long MOD=1e9+7;  
    long long binExpo(long long a,long long b){
    	long long res=1;
    	while(b){
    		if(b&1)res=(res*a)%MOD;
    		a=(a*a)%MOD;
    		b=(b>>1);
    	}
    	return res;
    }
    int modInverse(int denominator,int MOD){
    	return binExpo(denominator,MOD-2);
    }
    int findPermutation(string temp,vector<long long> &fact){
        int len = temp.size();
		vector<int> count(26,0);
		for(char ch:temp){
			count[ch-'a']++;
		}
		long long numerator=(fact[len])%MOD;
		long long denominator=1;
		for(int i=0;i<26;i++){
			if(count[i]>1){
				denominator=(fact[count[i]]*denominator)%MOD;
			}
		}
		int inverse=modInverse(denominator,MOD);
        long long ans=(inverse*numerator)%MOD;
		return ans;
    }
    void preProcessing(vector<long long> &fact){
		fact[0]=1;
        fact[1]=1;
        for(int i=2;i<(int)fact.size();i++){
            fact[i]=(fact[i-1]*i)%MOD;
        }
    }

    int countAnagrams(string s) {
        int len=s.size();
        vector<long long> factorial(len+1);
        preProcessing(factorial);
        stringstream ss(s);
        string temp;
        long long ans=1;
        while(ss>>temp){
            ans=(ans*findPermutation(temp,factorial))%MOD;
        }
        return ans%MOD;
    }
};