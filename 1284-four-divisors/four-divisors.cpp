class Solution {
public:
    vector<int>divisors(int n){
        vector<int>ans;
        int count = 0;
        for(int i = 1; i*i <= n; i++){
            if(n % i == 0){
                ans.push_back(i);
                if(i != n / i){
                    ans.push_back(n / i);
                }
            }
        }
        return ans;
    }
    int summation(vector<int>&ans){
        int tot = 0;
        for(int n : ans){
            tot += n;
        }
        return tot;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int num : nums){
            vector<int>res;
            res = divisors(num);
            if(res.size() == 4){
                total += summation(res);
            }
        }
        return total;
    }
};