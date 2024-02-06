class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        mp = {}
        temp = strs[:]
        
        for i in range(len(temp)):
            val = temp[i]
            temp[i] = ''.join(sorted(temp[i]))
            if temp[i] in mp:
                mp[temp[i]].append(val)
            else:
                mp[temp[i]] = [val]
        
        for key, value in mp.items():
            ans.append(value)
        
        return ans
