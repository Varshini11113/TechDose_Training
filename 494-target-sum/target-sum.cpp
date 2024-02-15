class Solution {
public:
    int Find(int index,int value,vector<int>&nums,int target){
        if(index==nums.size()){
            if(value==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        int pos=0,neg=0;
        // +ve take
        pos=Find(index+1,value+nums[index],nums,target);
        //-ve take
        neg=Find(index+1,value-nums[index],nums,target);
        
        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return Find(0,0,nums,target);
    }
};