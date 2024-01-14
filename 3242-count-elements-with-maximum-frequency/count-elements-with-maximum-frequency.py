class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mp = {}
        for x in nums:
            mp[x] = mp.get(x, 0) + 1
        maxi = 0
        for key, value in mp.items():
            maxi = max(maxi, value)
        ans = 0
        for key, value in mp.items():
            if value == maxi:
                ans += value
        return ans