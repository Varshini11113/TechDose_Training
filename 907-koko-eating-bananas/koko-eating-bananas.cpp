class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1;
        long long right = 1000000000;
        
        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long hours = 0;
            for(int pile : piles){
                long long div = pile / mid;
                hours += div;
                if(pile % mid != 0) hours++;
            }
            if(hours <= h) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};
