class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;
        while(left < right){
            int mid = left + (right - left) / 2;
            int hours = 0;
            for(int pile : piles){
                int div = pile / mid;
                hours += div;
                if(pile % mid != 0) hours++;
            }
            if(hours <= h) right = mid;
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};