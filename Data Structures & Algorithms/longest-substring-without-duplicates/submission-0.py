class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        r = 0
        hashmap = {}
        maxLen = 0
        while r < len(s):
            if s[r] in hashmap:
                maxLen = max(maxLen, r-l)
                l = max(l, hashmap[s[r]] + 1)
            hashmap[s[r]] = r
            r += 1
        return max(maxLen, r-l)
        