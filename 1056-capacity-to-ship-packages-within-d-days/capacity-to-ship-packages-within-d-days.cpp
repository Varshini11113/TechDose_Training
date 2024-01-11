class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min = *max_element(weights.begin(), weights.end());
        int max = accumulate(weights.begin(), weights.end(), 0);
        int mid;
        while(min <= max){
            mid = min + (max - min)/2;
            int curr = 0, day = 1;
            for(auto w : weights){
                if(curr + w > mid){
                    day++;
                    curr = 0;
                }
                curr += w;
            }
            if(day <= days){
                max = mid - 1;
            }
            else{
                min = mid + 1;
            }
        }
        return min;
    }
};