class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int amt = 0, res = INT_MAX;
        // int count = 0;
        // sort(prices.begin(), prices.end());
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i != j){
                    amt = prices[i] + prices[j];
                    res = min(res, amt);
                }
            }
            // cout<<amt;
            // amt += prices[i] + prices[i+1];
            // if(amt <= money){
            //     money -= amt;
            //     if(money > 0){
            //         return money;
            //     }
            // }
            // if(amt < money){
            //     // money -= amt;
            //     amt += prices[i];
            //     count++;
            // }
            // if(count >= 2){
            //     money-=amt;
            //     break;
            // }
        }
        int ans = money - res;
        if(ans >= 0) return ans;
        return money;
    }
};