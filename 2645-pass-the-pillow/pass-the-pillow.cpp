class Solution {
public:
    int passThePillow(int n, int time) {
        int d = 1;  
        int end_person = 1;  
        for (int i = 0; i < time; i++) {
            if (end_person == 1) {
                d = 1;
            }
            else if (end_person == n) {
                d = -1;
            }
            end_person += d;
        }
        return end_person;
    }
};