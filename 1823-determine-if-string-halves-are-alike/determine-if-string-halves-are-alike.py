class Solution(object):
    def halvesAreAlike(self, s):
        vowels="aeiouAEIOU"
        l=len(s)
        a=s[0:l//2]
        b=s[l//2:l+1]
        return sum(a.count(vowel) for vowel in vowels)==sum(b.count(vowel) for vowel in vowels)
           