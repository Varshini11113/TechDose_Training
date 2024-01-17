from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freq = Counter(arr)
        unique = set()

        for count in freq.values():
            if count in unique:
                return False
            unique.add(count)

        return True