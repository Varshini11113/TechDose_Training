class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int tot = numBottles;
        int empty = numBottles;
        while(empty >= numExchange){
            int newBottle = empty / numExchange;
            tot += newBottle;
            empty = newBottle + (empty % numExchange);
        }
        return tot;
    }
};