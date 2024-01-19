class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        mp = {}
        n = len(nums)
        
        for i in range(n):
            if nums[i] in mp:
                if abs(i - mp[nums[i]]) <= k:
                    return True
            mp[nums[i]] = i
        
        return False