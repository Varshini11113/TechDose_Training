class Solution:
    def isPalindrome(self, string: str) -> bool:
        if not string:
            return True
        for i in range(0, len(string) // 2 + 1):
            if string[i] != string[-1 - i]:
                return False
        return True
        
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.isPalindrome(word):
                return word
        return ''