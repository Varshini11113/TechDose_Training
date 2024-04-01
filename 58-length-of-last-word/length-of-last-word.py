class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        lis = s.strip().split(" ")
        length = len(lis)
        return len(lis[length-1])