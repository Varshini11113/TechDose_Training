class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n == 0 or k <= 0:
            return
        
        # Make a copy of nums
        nums_copy = nums[:]
        
        # Rotate the elements
        for i in range(n):
            nums[(i + k) % n] = nums_copy[i]

        