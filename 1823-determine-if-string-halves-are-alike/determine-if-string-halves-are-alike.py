class Solution(object):
    def isVowel(self, c):
        return c.lower() in {'a', 'e', 'i', 'o', 'u'}

    def halvesAreAlike(self, s):
        n = len(s)
        count = 0

        for i in range(n // 2):
            if self.isVowel(s[i]):
                count += 1

        for i in range(n // 2, n):
            if self.isVowel(s[i]):
                count -= 1

        return count == 0



        