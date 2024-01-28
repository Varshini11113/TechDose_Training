class Solution:
    def countKeyChanges(self, s: str) -> int:
        previous = s[0]
        count_changes = 0

        for ele in s:
            if ele != previous and ele.lower() != previous and ele.upper() != previous:
                previous = ele
                count_changes += 1

        return count_changes