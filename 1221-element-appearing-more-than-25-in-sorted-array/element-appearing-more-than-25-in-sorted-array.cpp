class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size();
        int twenty = size/4;
        int count = 1;
        int ele = arr[0];
        for(int i = 1; i<size; i++){
            if(arr[i] == ele){
                count++;
            }
            else{
                count = 1;
            }
            if(count > twenty) return arr[i];
            ele = arr[i];
        }
        return ele;
    }
};