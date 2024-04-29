class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int answer = 0;
        int XOR = 0;
        for(int n : nums){
            XOR ^= n;
        }
        k ^= XOR;
        while(k > 0){
            answer += k & 1;
            k >>= 1;
        }
        return answer;
    }
};