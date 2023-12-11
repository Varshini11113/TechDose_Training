class Solution(object):
    def findSpecialInteger(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        size = len(arr)
        qrt = size // 4
        ele = arr[0]
        count = 1
        for i in range(1, size):
            if arr[i] == ele:
                count+=1
            else:
                count = 1
            if count > qrt:
                return arr[i]
            ele = arr[i]
        return ele
        