class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0

        substring = dict()
        left = 0
        right = 0
        max_length = 1
        while(right < len(s)):
            c = s[right]
            if c in substring and substring[c] >= left:
                max_length = max(max_length, right-left)
                left = substring[c] + 1

            substring[c] = right
            right = right + 1

        max_length = max(max_length, right-left)

        return max_length
