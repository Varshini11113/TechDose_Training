class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums,long long int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                long long int target2 = target - nums[i] - nums[j];
                int left = j+1, right = n-1;
                while(left < right){
                    long long int sum = nums[left] + nums[right];
                    if(sum < target2) left++;
                    else if(sum > target2) right--;
                    else{
                        vector<int>quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        res.push_back(quad);
                        while(left < right && nums[left] == quad[2]) ++left;
                        while(left < right && nums[right] == quad[3]) --right;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) ++j; 
            }
            while(i+1 < n && nums[i] == nums[i+1]) ++i; 
        }
        return res;
    }
};