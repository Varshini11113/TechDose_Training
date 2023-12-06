class Solution {
public:
    int totalMoney(int n) {
        if(n <= 7){
            return (n*(n+1))/2;
        }
        int week_count = n / 7;
        int remaining_days = n % 7;
        
        int total = ((week_count * (week_count - 1)) / 2) * 7;
        total += week_count * 28; 
        total += ((remaining_days * (remaining_days + 1)) / 2) + (week_count * remaining_days); 
        
        return total;
    }
};