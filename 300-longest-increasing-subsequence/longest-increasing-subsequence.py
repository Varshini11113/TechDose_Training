class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ans = []
        ans.append(nums[0])
        for x in nums:
            if x > ans[-1]:
                ans.append(x)
            else:
                ind = bisect_left(ans, x)
                ans[ind] = x

        return len(ans)
