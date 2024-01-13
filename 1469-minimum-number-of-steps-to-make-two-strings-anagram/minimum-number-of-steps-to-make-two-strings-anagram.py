class Solution:
    def minSteps(self, s: str, t: str) -> int:
        count_s = [0] * 26
        count_t = [0] * 26

        for ch in s:
            count_s[ord(ch) - ord('a')] += 1

        for ch in t:
            count_t[ord(ch) - ord('a')] += 1

        steps = sum(abs(count_s[i] - count_t[i]) for i in range(26))

        return steps // 2
